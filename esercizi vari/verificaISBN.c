#include <stdio.h>

#define DIM 10

int verificaIsbn(char*);

int verificaIsbn(char* str){
  int sottosomme[DIM];
  int sommaTot;
  int somma;
  int i, j;
  
  for(i = 0, j = 0, somma = 0; str[i] != '\0'; i++){
    if(str[i] != '-'){
      if(j == 0){
        somma += str[i] - '0';
      }else{
        somma = str[i] + str[i-1];
      }
      sottosomme[j] = somma;
      j++;
    }
  } 
 for(i = 0, sommaTot = 0; i < DIM; i++)
   sommaTot += sottosomme[i];

 return sommaTot % 11;
}