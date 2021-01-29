#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minmaxstr(char*, char*, char*);

int main(int argc, char* argv[]){
 
 char max, min;
 if(argc == 2){
   minmaxstr(argv[1], &max, &min);
 }else{
   printf("errore negli argomenti\n");
 }  
 return 0;
}

void minmaxstr(char* str, char* min, char* max){
 int i;
 
 for(i = 0; str[i] != '\0'; i++){
   if(str[i] >= 'A' && str[i] <= 'Z')
     str[i] = str[i] - 'A' + 'a';
 }
 
 *max = *min = str[0];
 for(i = 1; str[i] != '\0'; i++){
   if(str[i] > *max)
     *max = str[i];
   else if(str[i] < *min)
     *min = str[i];
   }
}