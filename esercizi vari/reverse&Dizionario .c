#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 40
#define FN "DIC.txt"

char* reverse(char*);

int main(){
 char vocabolo[MAXS+1];
 char *invertito;
 FILE* fp;
 int found;
 
 scanf("%s", vocabolo);
 
 fp = fopen(FN, "r");
 if(fp){
   invertito = reverse(vocabolo);
   fscanf(fp, "%s", vocabolo);
   while(!feof(fp) && !found){
     found = !strcmp(invertito, vocabolo);
     fscanf(fp, "%s", vocabolo);
   }
   printf("%d\n", found);

   free(invertito);
   fclose(fp);
 }else{
   printf("Errore nell'apertura del file\n");
 }
 
 return 0;
}

char* reverse(char* str){
  int i, len;
  char* sInv;

  len = strlen(str); 
  sInv = malloc(sizeof(char)*(len+1));
  if(sInv){
    for(i = 0; i < len; i++){
      sInv[i] = str[len-i-1];
    }
  }else{
   printf("Errore\n");
  }
  return sInv;
}