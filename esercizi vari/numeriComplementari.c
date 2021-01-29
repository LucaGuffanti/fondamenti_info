#include <stdio.h>
#include <stdlib.h>

/*
uso una struttura dati che raccoglie gli elementi di una coppia.
nel sottoprogramma questo mi permette di allocare dinamicamente un array di
questa struttura dati. potrò così gestire in comodamente la dimensione dell'array in questione, trasferendo all'utente
anche la dimensione di questo, pari alla divisione intera tra il numero n e 2.
*/

typedef struct{
 int n;
 int compl_n;
} coppia_t;

coppia_t* calcolaComplementari(int n, int* dim){
  coppia_t* insiemeCoppie;
  int i;

  *dim = n/2;
  insiemeCoppie = malloc(sizeof(coppia_t)*(*dim);

  if(insiemeCoppie){
   for(i = 1; i < *dim; i++){
     insiemeCoppie[i]->n = i;
     insiemeCoppie[i]->compl_n;
   }
  }else{
    printf("Errore nell'allocazione\n");
  }
  return insiemeCoppie;
}