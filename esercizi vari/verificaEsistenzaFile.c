#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verificaEsistenza(char*, char*);

int verificaEsistenza(char* percorso, char* nome){
 int i, len1, len2, esito;
 FILE* fp;
 char* nomeCompleto;
 
 len1 = strlen(percorso);
 len2 = strlen(nome);
 
 esito = 0;
 nomeCompleto = malloc(sizeof(char)*(len1+len2+1));
 if(nomeCompleto){
  for(i = 0; percorso[i]!='\0'; i++){
    nomeCompleto[i] = percorso[i];
  }
  for(; nome[i]!='\0'; i++){
    nomeCompleto[i] = nome[len1 - i];
  }
  nomeCompleto[i] = '\0';
  fp = fopen(nomeCompleto, "r");
  if(fp){
    esito = 1; 
    fclose(fp);
  }   
  else
    esito = 0;
 }else{
  printf("Errore nell'allocazione della stringa\n");
 }  
 free(nomeCompleto);
 return esito;
}