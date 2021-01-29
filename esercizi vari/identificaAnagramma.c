#include <stdio.h>
#include <string.h>

int isAnagramma(char*, char*);

int isAnagramma(char* str1, char* str2){
  int esito;
  int i, len, j, found;
  int *visto;
   
  esito = 0;
  len1 = strlen(str1);
  len2 = strlen(str2);
  if(strcmp(str1, str2) || ){
    esito = 0;
    return esito;
  }
  visto = malloc(sizeof(int)*len1);
  if(visto){
    for(i = 0; i < len1; i++)
      visto[i] = 0;

    for(i = 0; str1[i] != '\0'; i++){
      for(j = 0, found = 0; str2[j] != '\0' && !found; j++){
        if(str1[i] == str2[j]){
          if(visto[j] == 0){
            visto[j] = 1;
            found = 1;
          }   
        }
      }
    }

    for(i = 0, esito = 1; i < len1 && esito; i++)
      if(visto[i] != 1)
        esito = 0;
    free(visto);
  }else{
    printf("Errore nell'esecuzione\n");
  }  
  return esito;
}