#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include <ctype.h>

#define INICIO 0
#define FINAL 1

int main(void) {
     tnodo *head = NULL;
     int pos = 1;
  int interruptor = 0;
 FILE* stream = fopen("dataC.csv", "r");

    char line[1024];
    while (fgets(line, 1024, stream))
    {
      char * nameData;
       nameData = strtok(line,",");
       int ageData = 0;
       ageData = atoi( strtok(NULL, "") );
     
      if(interruptor ==1){
           insertar_nodo(&head, FINAL,  ageData, nameData, pos);
         pos++;
        }

       if(interruptor == 0){
         insertar_nodo(&head, INICIO,  ageData, nameData, pos);
         interruptor = 1;
         pos++;
      }
    }
    free(stream);

int input;
char c;
char input2[50];
interruptor=0;
puts("Axel Octavio Meinguer\nJosé María Rendón\n\nWhich action do you action do you want? \n(1) Print linked list \n (2) Print the oldest person \n (3) Print the youngest person \n (4) Print the average of ages \n (5) Print all names that start with the given letter\n");

printf("\nThe size of the linked list is of %d elements\n", listaSize(head) );

scanf(" %i",&input);



switch(input){
  case 1 :
  puts("\n");
  imprime_lista(head);
  break;

case 2 :
getOldest(head);
break;

case 3 :
getYoungest(head);
break;

case 4 :
getAverage(head);
break;

case 5 :

interruptor = 1;
puts("\nEnter a character that will be the first one of the name search:");
break;

  default :
  puts("\nThats not an option");

 

}

if (interruptor==1){

scanf(" %c", &c);
puts("\n------------------------------");
c = toupper(c);

strcpy(input2, &c);
getNames(input2, head);

}

libera_lista(&head);
}
