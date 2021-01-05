

int invertiNumero(int);

int invertiNumero(int n){
 int cifra;
 int inverso;
 
 inverso = 0;
 while(n > 0){
   cifra = n%10;
   inverso = inverso*10 + cifra;
   n = n/10;
 }
 return inverso;
}