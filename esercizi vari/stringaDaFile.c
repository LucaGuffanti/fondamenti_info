#include <stdio.h>
#define FN "prova.txt"
#define DIM 30
int main(int argc, char* argv[]){
  char str[DIM+1];
  FILE* fp;
  fp = fopen(FN, "r");
  if(fp){
      fscanf(fp, "%s",  str);
      while(!feof(fp)){
          printf("%s\n", str);
          fscanf(fp, "%s", str);
      }
      fclose(fp);
  }else{
      printf("Errore\n");
  }
  return 0;
}