int lefttprime(int);

int lefttprime(int val){
 int n;
 int grado;
 int pot;
 int i;
 int prime;
 
 n = val;
 grado = 0;
 while(n > 0){
  grado++;
  n = n/10;
 }
 
 
 n = 0;
 while(grado != 0 && prime){
    
   n = val;
   for(i = 2; i*i<=n && prime;i++){
     if(n%i == 0)
       prime = 0; 
   }
     
   for(i = 0, pot = 1; i < grado-1; i++){
     pot = pot*10;
   }     
 
   val = val%pot;    

   grado--;
 }

 return prime;
}