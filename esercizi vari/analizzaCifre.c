#include <studio.h>

#define BASE 10

int cercaFreqMax(int);

int cercaFreqMax(int num){
 int numeri[BASE];
 int cifra;
 int max, maxIndex;
 int i;
 int pari;
 
 for(i = 0; i < BASE; i++){
   numeri[i] = 0;
 }
 while(num > 0){
   cifra = num%BASE;
   numeri[cifra]++;
   num = num/BASE;
 }
 
 for(i = 0 && pari = 0; i < len && !pari; i++)
   if(i%2 == 0 && numeri[i] != 0)
     pari = 1;
 
 

 if(pari){
  max = numeri[0];
  maxIndex = 0;
  for(i = 1; i < BASE; i++){
   if(numeri[i] < max && i%2 == 0){
     max = numeri[i];
     maxIndex = 1;
   }
 }
 else{
 max = numeri[1];
 maxIndex = 1;
 for(i = 2; i < BASE; i++){
   if(numeri[i] > max && i%2 != 0){
     max = numeri[i];
     maxIndex = 1;
   }
 }

 }
 return maxIndex;
}