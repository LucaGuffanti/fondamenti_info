#include <stdio.h>
#include <string.h>

#define FILENAME "dizionario.txt"
#define MAXS 35

int main(){
  
 FILE* fp;
 char vocabolo[MAXS+1];
 char mascheraVocali[MAXS+1];
 int ordineVocali;
 int i, j, len;
 
 fp = fopen(FILENAME, "r");
 if(fp){
    fscanf(fp, "%s", vocabolo);
    while(!feof(fp)){
      len = strlen(vocabolo);
      for(i = 0; i < len; i++)
        mascheraVocali[i] = 'b';
      for(i = 0, j = 0; vocabolo[i] != '\0'; i++){
        if(vocabolo[i] == 'a' || vocabolo[i] == 'e' || vocabolo[i] == 'i' || vocabolo[i] == 'o' || vocabolo[i] == 'u'){       
          mascheraVocali[j] = vocabolo[i];
          j++;
        }
      }
      mascheraVocali[j] = '\0';
      for(i = 0, ordineVocali = 1; mascheraVocali[i + 1] != '\0'; i++){
        if(mascheraVocali[i] > mascheraVocali[i+1])
          ordineVocali = 0;
      }
      if(ordineVocali)
        printf("%s\n", vocabolo);
     
      fscanf(fp, "%s", vocabolo);
    }
    fclose(fp);
 }else{
   printf("Errore\n");
 } 


 return 0;
}