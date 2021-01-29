#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int num;
 struct nodo_* next;
} nodo_t;

nodo_t* delete(nodo_t* h, int val){
  nodo_t* succ;
  nodo_t* prec;
 
  for(prec = NULL, succ = h; succ && prec; prec = succ, succ = succ->next){
    if(succ->num == val){
      prec->next = succ->next;
    }
  }
  return h;
}

nodo_t* increasing(nodo_t* h, int val){
 nodo_t* tmp;
 nodo_t* curr;
 nodo_t* prec;
 
 prec = NULL;
 curr = NULL;
 tmp = NULL;
 tmp = malloc(sizeof(nodo_t));
 if(tmp){
  tmp->num = val;
  tmp->next = NULL;
  if(h){
   if(val <= h->n){
    tmp->next = h->next;
    h = tmp;
   }else{
    for(curr = h; curr && curr->n <= val; prec = curr, curr = curr->next);
    tmp->next = curr;
    prec->next = tmp;
   }
  }else{
    h = tmp;
  }
 }else{
   printf("Errore\n");
 }
 return h;
}