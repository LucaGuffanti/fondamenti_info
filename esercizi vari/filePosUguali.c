#include <stdio.h>

#define FNDIM 80 

int main(){
 FILE *fp1, *fp2;
 char fn1[FNDIM+1], fn2[FNDIM+1];
 char c1, c2;
 int i, j, contaUguali;
 scanf("%s %s", fn1, fn2);
 
 fp1 = fopen(fn1, "r");
 if(fp1){
  fp2 = fopen(fn2, "r");
  if(fp2){
    fscanf(fp1, "%c", c1);
    fscanf(fp2, "%c", c2);
    while(!feof(fp1) && !feof(fp2)){
      if(c1 == c2)
        contaUguali++;
    }
    if(feof(fp1)){
      printf("%s\n", fn2);
    }
    else if(feof(fp2){
      printf("%s\n", fn1);
    }
    else{
     printf("---\n");
    }
    printf("%d\n", contaUguali);
    fclose(fp1);
    fclose(fp2);       
  }else{
    printf("Errore nell'apertura del file\n");
  }
 }else{
   printf("Errore nell'apertura del file\n");
 }
 return 0;
}