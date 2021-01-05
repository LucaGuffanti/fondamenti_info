#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_ *next;
} nodo_t;

nodo_t* filtraNumeri(int [], int, int);
nodo_t* inserisciInCoda(nodo_t*, int);


nodo_t* filtraNumeri(int v[], int dim, int limite){
 nodo_t* h;
 int i;
 
 h = NULL;
 for(i = 0; i < dim; i++){
   if(v[i] > limite)
     h = inserisciInCoda(h, v[i]);
 }
 return h;
}

nodo_t* inserisciInCoda(nodo_t* h, int num){
 nodo_t* tmp;
 nodo_t* curr;

 tmp = curr = NULL;
 
 tmp = malloc(sizeof(nodo_t));
 if(tmp){
  tmp->next = NULL;
  tmp->n = num;
  if(h){
   for(curr = h; curr->next; curr = curr->next);
   curr->next = tmp;
  }else{
    h = tmp;
  }
 }else{
   printf("Errore nell'allocazione\n"); 
 }
 return h;
} 