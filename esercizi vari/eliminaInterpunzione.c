#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filtraInterpunzione(char* s1){
 char* s2;
 int len;
 int conta;
 int i, j;
 
 len = strlen(s1);
 s2 = malloc(sizeof(char)*(len+1);
 if(s2){  
   for(i = 0, j = 0, conta = 0; s1[i] != '\0'; i++){
     if((s1[i] >= 'a' && s1[i] <='z') || (s1[i] >= 'A' && s1[i] <='Z') || s1[i] != ' '){
      s2[j] = s1[i];
      j++;
     }else{
      conta++;
     }
   }
   s2[j] = '\0';
   strcpy(s1, s2);
 }else{
   printf("Errore\n");
 } 
 return conta;
}