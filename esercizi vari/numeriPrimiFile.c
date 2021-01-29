int main(int argc, char* argv[]){
 
 FILE* data;
 FILE* ris;
 int num;
 int i, j, isPrime;
 int contaPrimi;
 
 if(argc == 3){
   data = fopen(argv[1], "r");
   if(data){
     ris = fopen(argv[2], "w");
     if(ris){
       fscanf(data, "%d", &num);
       while(!feof(fp)){
         contaPrimi = 0;
         for(i = 2; i <= num; i++){
           for(j = 2, isPrime = 1; j*j <= i && isPrime; j++){
             if(i%j == 0)
              isPrime = 0;
           }
           if(isPrime)
             contaPrimi++;
         }
         fprintf(ris, "%d %d", num, contaPrimi);
         fscanf(data, "%d", &num);
       }
     }else{
       printf("Errore\n");
     }
   }else{
     printf("Errore\n");
   }
 }else{
   printf("Errore negli argomenti\n");
 }
 return 0;
}