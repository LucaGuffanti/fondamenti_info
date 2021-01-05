#include <stdio.h>

void separaSottostringhe(char*, char);

void separaSottostringhe(char* src, char sep){
 int i;
 for(i = 0; src[i] != '\0'; i++){
   if(src[i] == sep)
     printf("\n");
   else
     printf("%c", src[i]);
 }
}

