#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char c;
  int occorrenze;
} coppia_t;

coppia_t* filtraOccorrenze(char*);

coppia_t* filtraOccorrenze(char* str){
  coppia_t* coppia;
  int i, len, found, j, dimCoppia;

  len = strlen(str);
  coppia = malloc(sizeof(coppia_t)*len);
  if(coppia){
    for(i = 0, dimCoppia = 0; str[i] != '\0'; i++){
      for(j = 0, found = 0; j < dimCoppia && !found; j++){
        if(str[i] == coppia[j].c)
          found = 1;
      }
      if(!found){
        coppia[j].c = str[i];
        coppia[j].occorrenze = 1;
        dimCoppia++;
      }
      else if(found){
        j--;
        coppia[j].occorrenze++;
      }
    }
  }else{
    printf("Errore nell'allocazione della struttura dati\n");
  }
  return coppia;
}