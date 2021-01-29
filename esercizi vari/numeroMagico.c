#include <stdio.h>

#define FN 30

int main(int argc, char* argv[]){
  FILE* fp;
  int prod;
  int num;
  int contaDiv; 
  char filename[FN + 1];
  
  scanf("%s", filename);
  
  fp = fopen(filename, "r");
  if(fp){
    prod = 1;
    for(i = 0; i < 10; i++){
      fscanf(fp, "%d", &num);
      prod = prod * num;
    }
   
    for(i = 1, contaDiv = 0; i <= prod; i++){
       if(prod%i == 0)
         contaDiv++;
    }
    num = contaDiv%10;
    printf("%d\n", num);
    fclose(fp);  
  }else{
    printf("Errore nell'apertura del file\n");
  }
  return 0;
}