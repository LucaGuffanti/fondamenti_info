#include <stdio.h>
#include <string.h>

#define MAXRIGA 100


int main(int argc, char* argv[]){
 
 FILE* fp;
 char maxRiga[MAXRIGA + 1];
 char riga[MAXRIGA + 1];
 int maxC, contaC, i, contaRighe, sommaC;
 float meanC;
  
 if(argc == 2){
   
   fp = fopen(argv[1], "r");     
   if(fp){
     maxC = 0;
     contaC = 0;
     meanC = 0;
     sommaC = 0;
     contaRighe = 0;

     fscanf("%[^\n]", riga);
     while(!feof(fp)){
         contaRighe++;
	 for(i = 0; riga[i] != '\0'; i++){
         if(riga[i] != ' ')
           contaC++;
         }
         if(contaC > maxC){
           maxC = contaC;
	   strcpy(maxRiga, riga);
         }
         sommaC += contaC;
         fscanf("%[^\n]", riga);     
     }           
     meanC = (float)(sommaC)/contaRighe;
     printf("%d,\n %d,\n %d, %f,\n %s\n", contaRighe, sommaC, maxC, meanC, maxRiga);
     fclose(fp);
   }else{
     printf("Errore nell'apertura del file\n");
   }
 }else{
  printf("Errore negli argomenti\n");
 }
 return 0;
}