#include <stdio.h>

#define MAXDIM 80

int main(int argc, char* argv[]){
 FILE *fp;
 char filename[MAXDIM + 1];
 int cont;
 char c;

 scanf("%s", filename);
 
 fp = fopen(filename, "r");
 if(fp){
  cont = 0;
  fscanf(fp, "%c", &c);
  while(!feof(fp)){
    if(c >= '0' && c <= '9')
      cont++;
  }
  prtinf("%d\n", cont);
  fclose(fp);
 }else{
   printf("Errore nell'apertura del file\n"); 
 } 

 return 0;
}