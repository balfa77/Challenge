#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INICIO 0
#define FINAL 1

//Se define la estructura del nodo
struct nodo
{
  int age;
  char *name;
  int contador;
  struct nodo *sig;
};
//Se crea un alias de 'struct nodo' como tnodo
typedef struct nodo tnodo;

//************************

//Crea en memoria una instancia de tnodo//el malloc reserva en memoria los datos


void reorganizarLista(tnodo *head)
{
  tnodo *aux=head;
  int i = 1;
//debug
   //  puts("\nReordering the NODE's position index...\n");
  while(aux != NULL)
  {
   aux->contador = i;
   i++;
    aux = aux->sig;
  }//while

}//Reordena los indices de posicion de cada nodo

tnodo *crear_nodo(int age, char *name, int contador)
{
  //printf("2\n");
  tnodo *aux = (tnodo *)malloc(sizeof(tnodo));
  aux->age = age;
  aux->name = (char *)malloc(strlen(name)+1);//reservo en espacio de memoria el nombre + el caracter que me indica que terminó 
  //aux->name[0] = '\0'; //inicializo como cadena vacia el vector de caracteres
  strcpy(aux->name, name); //se copia a la cadena destino una cadena de origen
  aux->contador = contador;
  aux->sig = NULL;
  //printf("3\n");
  return aux;
}//crear_nodo

void insertar_nodo(tnodo **head,int pos, int age, char *name, int contador)
{
    //printf("1\n");
    tnodo *nuevo = crear_nodo(age, name, contador);
    //printf("4-*nuevo=%d\n",nuevo);
    tnodo *aux;

    if(*head == NULL)
    {
      *head = nuevo;
      //printf("5-*head=%d\n",*head);
    }
    else
    {

      if (pos == FINAL)
      { //Insertar nodo al final de la lista
        //printf("6\n");
        aux = *head;
        while(aux->sig != NULL)
          aux = aux->sig;
        aux->sig = nuevo;
      }//if
      else
      {//Insertar nodo al inicio de la lista
        //printf("7\n");
        nuevo->sig = *head;
        *head = nuevo;
      }//else

  reorganizarLista(*head);

    }//else



}//insertar_nodo

void imprime_lista(tnodo *head)
{
  tnodo *aux=head;

  printf("LIST: START \n");
  while(aux != NULL)
  {
    printf("Age = %d  |  ", aux->age);
    printf("Name = %s  |  ", aux->name);
    printf("Postion Index = %d  \n", aux->contador);
    
    aux = aux->sig;
  }//while
  printf("LIST: END \n");
  printf("==================================\n");
}//imprime_lista




void removerItem(tnodo **head, int pos)
{

  tnodo *ant, 
        *ult=*head,
        *pul=*head;
  
  if (*head != NULL)
  {
    if (pos == INICIO)
    {
      ant = *head;
      *head = (*head)->sig;
      free(ant);
    }
    else 
    {
      while(ult->sig != NULL)
      {
        pul = ult;
        ult = ult->sig;
      }
      if (pul == ult)
      {//Hay un nodo, el penultimo y ultimo son iguales
        ant = *head;
        *head = (*head)->sig;
        free(ant);
      }
      else
      {//Hay más de 1 nodo en la lista, penúltimo y ultimo no son iguales
        pul->sig = NULL;


        free(ult);
      }
    }
  }

reorganizarLista(*head);

}

int listaSize(tnodo *head){
tnodo *aux=head;
int n = 0;
  while(aux != NULL||aux == NULL)
  {

  if(aux->sig == NULL){
    n = aux->contador;
    break;
  }

  aux = aux->sig;
  }
  return n;
}

void removerNodoEspecifico(int n, tnodo *head){
 tnodo *current=head;
 tnodo *previo;
 tnodo *siguiente;

  if(n > 1){ 
  while(current != NULL)
  {
    siguiente = current->sig;

    if(current->contador == n){
      previo->sig = siguiente;
      reorganizarLista(head);
      break;
    }

    previo = current;
    current =current->sig;
  
    }//while
  }else{
   removerItem(&head,INICIO); 
  }

}

void getNames(char a[50], tnodo *head){
  tnodo *aux=head;
char temp[50];

  while(aux != NULL)
  {
    strcpy(temp, aux->name);
    
   if(temp[0] == a[0]){
        printf("%s\n", aux->name);
   }
  

    aux = aux->sig;
  }
}

void getNodoEspecifico(int n, tnodo *head){
  tnodo *aux=head;

  while(aux != NULL)
  {
    if(aux->contador == n){
      puts("\nThe NODE was FOUNDED");
       printf("==================================\n");
      printf("Age = %d\n", aux->age);
    printf("Name = %s\n", aux->name);
    printf("Position Index = %d\n", aux->contador);
    break;
    }

  aux = aux->sig;
  if(aux == NULL){
    puts("\nThe NODE is not on the list:");
     printf("==================================\n");
  }
  }
}

int getOldest( tnodo *head){
  tnodo *aux=head;
int age=1;
char* ager;
  while(aux != NULL)
  { 
if(aux->age >= age){
  age = aux->age;
}
  aux = aux->sig; 
  }
  printf("Oldest age: %d \n", age);
  puts("\nPeople with that age:\n");
  aux=head;
 while(aux != NULL)
  { 
if(aux->age == age){
  printf("%s\n", aux->name);
}
  aux = aux->sig; 
  }

  return age;

}

int getYoungest( tnodo *head){
  tnodo *aux=head;
int age=9999;
int interruptor = 1; //debugger for age of 0 or NULL

  while(aux != NULL)
  {
if(interruptor==0){   
if(aux->age < age){
  age = aux->age;
} 
}
if(interruptor==1){
  interruptor =0;
}
 aux = aux->sig;
  }
  printf("Youngest age: %d", age);
  puts("\nPeople with that age:\n");
  aux=head;
 while(aux != NULL)
  { 
if(aux->age == age){
  printf("%s\n", aux->name);
}
  aux = aux->sig; 
  }
  return age;

}


float getAverage( tnodo *head){
  tnodo *aux=head;
int ageSum=0;
int interruptor = 1;
int counter=0;

  while(aux != NULL)
  {

if(interruptor==0){
     
ageSum+= aux->age;
counter++;
  
}
 
if(interruptor==1){
  interruptor =0;
}

 aux = aux->sig;

  }
float result = (ageSum / counter);
  printf("The average of all ages: %f", result);
  float age;

}

void libera_lista(tnodo **head)
{
  tnodo *aux=*head,
        *ant;

  while(aux != NULL)
  {
    free(aux->name);
    ant = aux;
    aux = aux->sig;
    free(ant);
  }//while  

  *head = NULL;
}//libera_lista

/*
int main(void) {
  tnodo *head = NULL;


  
  insertar_nodo(&head, INICIO,  55, "Rosa", 1);
  insertar_nodo(&head, FINAL, 25, "Juan", 2);
  insertar_nodo(&head, FINAL,  30, "Pedro", 3);
  insertar_nodo(&head, FINAL,  35, "Claudia", 4);
  insertar_nodo(&head, FINAL,  7, "Sheva", 5);
  puts("\n[ Generating the list ]\n");
  imprime_lista(head);

  puts("\nRemove an element at the start\n");
  removerItem(&head,INICIO);
  imprime_lista(head);

  puts("\nRemove an element at the end\n");
  removerItem(&head,FINAL);
  imprime_lista(head);

puts("\nAdd an element at the start\n");
  insertar_nodo(&head, INICIO,  2, "Rodrigo", 6);
  imprime_lista(head);

puts("\nAdd an element at the end\n");
   insertar_nodo(&head,FINAL,  9, "Ness", 7);
  imprime_lista(head);

printf("\nThe size of the linked list is of %d elements\n", listaSize(head) );

int input;
puts("\nWhich element do you want to get?\n");
scanf("%i",&input);
getNodoEspecifico(input, head);

printf("==================================\n");
input = -1;
puts("\nWhich element do you want to remove?\n");
scanf("%i",&input);
removerNodoEspecifico(input, head);
imprime_lista(head);

  libera_lista(&head);
  puts("\nJose Maria  \nAxel Octavio");
  

}*/
