#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_* next;
} nodo_t;

nodo_t* inserireInCoda(nodo_t*, int);
nodo_t* inserireAlternato(nodo_t*, nodo_t*);
void visualizza(nodo_t*);
nodo_t* eliminaLista(nodo_t*);

int main(){
 nodo_t* l1;
 nodo_t* l2;
 nodo_t* l3;

 l1 = l2 = l3 = NULL;

 l1 = inserireInCoda(l1, 1);
 l1 = inserireInCoda(l1, 3);
 l1 = inserireInCoda(l1, 5);
 l1 = inserireInCoda(l1, 7);
 l1 = inserireInCoda(l1, 9);
 l1 = inserireInCoda(l1, 11);

 l2 = inserireInCoda(l2, 2);
 l2 = inserireInCoda(l2, 4);
 l2 = inserireInCoda(l2, 6);
 l2 = inserireInCoda(l2, 8);

 visualizza(l1);
 visualizza(l2); 

 l3 = inserireAlternato(l1, l2);
 
 visualizza(l3);

 eliminaLista(l1);
 eliminaLista(l2);
 eliminaLista(l3);
 
 return 0;
}

nodo_t* inserireInCoda(nodo_t* h, int num){
 nodo_t* tmp;
 nodo_t* curr;

 tmp = curr = NULL;

 tmp = malloc(sizeof(nodo_t));
 if(tmp){
  tmp->n = num;
  tmp->next = NULL;

  if(h){
    for(curr = h; curr->next; curr = curr->next);
    curr->next = tmp;
  }else{
   printf("Ci passo\n");
   h = tmp;
  }  
 }else{
   printf("Errore nell'allocazione del nodo della lista\n");
 }

 return h;
}

nodo_t* inserireAlternato(nodo_t* l1, nodo_t* l2){
  nodo_t* curr1;
  nodo_t* curr2;
  nodo_t* l3;
  
  l3 = NULL;
  for(curr1 = l1, curr2 = l2; curr1 && curr2; curr1 = curr1->next, curr2 = curr2->next){
    l3 = inserireInCoda(l3, curr1->n);
    l3 = inserireInCoda(l3, curr2->n);
  }
  if(curr1){
    printf("L1 e' piu' lunga\n");
    for(; curr1; curr1 = curr1->next)
      l3 = inserireInCoda(l3, curr1->n);
  }
  else if(curr2){
    printf("L2 e' piu' lunga\n");
    for(; curr2; curr2 = curr2->next)
     l3 = inserireInCoda(l3, curr2->n);
  }
 
 return l3;
}

void visualizza(nodo_t* h){
  for(; h; h = h->next)
    printf("%d", h->n);
  printf("\n");
}

nodo_t* eliminaLista(nodo_t* h){
  nodo_t* tmp;
  tmp = h;
  while(h){
    h = h->next;
    free(tmp);
    tmp = h;
  }
  return NULL;
}