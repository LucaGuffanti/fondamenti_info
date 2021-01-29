#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_* next;
} nodo_t;

typedef struct nodoC{
 int n;
 int occorrenze;
 struct nodoC* next;
} compatto_t;

compatto_t* compactList(nodo_t*);

compatto_t* compactList(nodo_t* l1){
 compatto_t* lC;
 compatto_t* tmp;
 int found;
 lC = NULL;
 for(; h; h = h->next){
   for(tmp = lC, found = 0; tmp && !found; tmp = tmp->next){
     if(tmp->n == h->n){
       tmp->occorrenze += 1;
       found = 1;
     }
   }
   if(!found){
     lC = increasing(lC, h->n);
   }
   
   for(tmp = lC, found = 0; tmp && !found; tmp = tmp->next){
    if(tmp->n == h->n){
      tmp->occorrenze += 1;
      found = 1;
   }
 }
}