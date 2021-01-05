#include <stdio.h>
#define BASE 10

int maxCifra(int);

int main(){
 int n;
 scanf("%d", &n);
 printf("%d\n", maxCifra(n)); 

 return 0;
}

int maxCifra(int n){
 int num;
 if(n/BASE == 0){
   return n%BASE;
 }
 else{
   num = maxCifra(n/BASE);
   if(n%BASE > num)
    return n%BASE; 
   else
    return num;
 }
}