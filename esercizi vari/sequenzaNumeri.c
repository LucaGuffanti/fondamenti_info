#include <stdio.h>

int main(){
 int num, succ;
 int esito;

 scanf("%d", &num);
 succ = num;
 esito = 1; 

 while(num != 0 && esito){
   esito = num == succ;
   succ++;
   if(esito)
    scanf("%d", &num);
 }  

 printf("%d\n", esito); 
 if(!esito)
  printf("%d\n", succ-1);
 return 0;
} 