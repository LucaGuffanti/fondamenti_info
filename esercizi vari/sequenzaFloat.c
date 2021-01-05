#include <stdio.h>

int main(int argc, char* argv[]){
 float n, max, min;
  
 scanf("%d", &n);
 max = min = n; 
 while(n!=0.0f){
   if(n > max)
     max = n;
   else(n < min)
     min = n;
 }

 printf("%f, %f\n", max, min);
  
 return 0;
}