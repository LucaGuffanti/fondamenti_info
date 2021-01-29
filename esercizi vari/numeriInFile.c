#include <stdio.h>

int main(int argc, char* argv[]){
 
 int max, min, cont, som, val;
 float media;
 FILE* fp;
  
 if(argc == 2){
  fp = fopen(argv[1], "r");
  if(fp){
   fscanf(fp, "%d", &val);
   max = min = val;
   som = 0;
   while(!feof(fp)){
     cont++;
     som = som + val;
     if(val > max)
       max = val;
     else if(val < min)
       min = val;

     fscanf(fp, "%d", &val);
   }   
    
   media = (float)(som)/cont;  
   printf("%d, %d, %f\n", max, min, media);
   fclose(fp);
  }else{
    printf("Errore nell'apertura del file");
  }
 }else{
   printf("Errore negli argomenti");
 }

 return 0;
}