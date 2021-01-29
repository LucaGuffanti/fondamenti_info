#include <stdio.h>

#define DIM_ANNO 4
#define DIM_MESE 2
#define DIM_GIORNO 

typedef struct data_{
 int anno, mese, giorno;
} tdata;

void filtraTitolo(char*, tdata*, char*);

void filtraTitolo(char* nomeFile, tdata* data, char* nome){
  int i, j;
  int lenNome;
  
  data->anno = data->mese = data->giorno = 0;
  
  for(i = 0; i < DIM_ANNO; i++){
    data->anno = (data->anno * 10) + (nomeFile[i] + '0'); 
  }
  for(; i < DIM_MESE; i++){
   data->mese = (data->mese * 10) + (nomeFile[i] + '0');
  }
  for(; i < DIM_GIORNO; i++){
   data->giorno = (data->giorno * 10) + (nomeFile[i] + '0');
  }
  j = i;

  for(; nomeFile[i] != '\0'; i++);
  lenNome = i - (DIM_ANNO + DIM_MESE + DIM_GIORNO) - 2;

  nome = malloc(sizeof(char)*(lenNome+1));
  if(nome){
   for(j = 0; nome[j] != '\0' && nomeFile[j + DIM_ANNO + DIM_MESE + DIM_GIORNO] != '.' && ; j++)
     nome[j] = nomeFile[j + DIM_ANNO + DIM_MESE + DIM_GIORNO];
   
   nome[j] = '\0';
  }else{
    printf("Errore nell'allocazione della memoria\n");
  }
}