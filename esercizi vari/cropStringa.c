#include <stdio.h>

char* crop(char*, char);

int main(int argc, char* argv[]){
 char* cropped;
 if(argc == 3){
  cropped = crop(argv[1], argv[2]);
  if(cropped)
    printf("%s\n", cropped);
  else
    printf("(null)\n");
  free(cropped);
 }else{
   printf("Errore argomenti\n"); 
 }
 return 0;
}

char* crop(char frase, char ch){
 int indexB, indexE, i, len;
 char* cropped;

 cropped = NULL;
 indexB = indexE = -1;
 for(i = 0; frase[i] != '\0'; i++){
   if(frase[i] == ch && indexB == -1)
     indexB = i;
   else if(frase[i] == ch && indexB != -1)
     indexE = i;
 }

 if(indexB == -1 || indexE == -1){
   return cropped;  
 }else{
   len = indexE - indexB;
   cropped = malloc(sizeof(char)*len);
   if(cropped){
     for(i = indexB+1; i < indexE; i++)
        cropped[i - indexB - 1] = frase[i];
     cropped[i] = '\0';
   }else{
     printf("Errore allocazione\n");
   }
  return cropped;   
 }
}