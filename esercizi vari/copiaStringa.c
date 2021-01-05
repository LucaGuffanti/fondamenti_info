#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copiaStringa(char*, char*);

void copiaStringa(char *s1, char *s2){
 int len, i;

 len = strlen(s1);
 s2 = malloc(sizeof(char)*(len+1));

 if(s2){
  for(i = 0; s1[i]!='\0'; i++)
    s2[i] = s1[i];
  s2[i] = '\0';   
 }else{
   printf("Errore\n");
 } 

}