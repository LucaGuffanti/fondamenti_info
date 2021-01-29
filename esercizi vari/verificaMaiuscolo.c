#include <stdio.h>

#define DIMFN 30
#define MAXS 80
int main(int argc, char* argv[]){
 
 char filename[DIMFN + 1];
 char riga[MAXS + 1]; 
 FILE* fp;
 
 scanf("%s", filename);
 fp = fopen(filename, "r");
 if(fp){
   fscanf(fp, "%[^\n]", riga);
   while(!feof(fp)){
     if(riga[0] >= 'A' && riga[0] <= 'Z')
       printf("%s\n", riga); 
     fscanf(fp, "%[^\n]", riga);
   }
   fclose(fp);
 }else{
   printf("Errore nell'apertura/accesso del file");
 }
 return 0;
}