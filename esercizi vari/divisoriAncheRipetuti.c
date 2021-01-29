#define BASE 10

int contaDivisiori(int);

int contaDivisori(int n){
 int num;
 int cifra;
 int conta;
 
 num = n;
 conta = 0;
 while(n > 0){
   cifra = n%BASE;
   if(num != 0){
     if(num%cifra == 0){
       conta++;
     }
   }
   n = n/BASE;
   
 }
 
 return conta;
}