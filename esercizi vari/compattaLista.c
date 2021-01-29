#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_* next;
} nodo_t;

typedef struct comp_{
 int n;
 int occorrenze;
 struct comp_* next;
} compatto_t*;

compatto_t* compattaLista(nodo_t*);
compatto_t* inserisciInCoda(compatto_t*, int, int);

compatto_t* compattaLista(nodo_t* l1){
  int num, volte, i;
  compatto_t* l2;
  compatto_t* curr;
  nodo_t* help;
  nodo_t* tmp;
  
  l2 = NULL;
  curr = NULL;
  help = NULL;
  tmp = NULL;

  for(; l1; l1 = l1->next)
   help = increasing(help, l1->n);

  for(tmp = help; tmp; help = help->next){
    if(help->n == tmp->n)
      volte++;
    else if(help->n != tmp->n){
      l2 = inserisciInCoda(l2, tmp->n, volte);
      tmp = help;
      volte = 0;  
    }
  }
}

compatto_t* inserisciInCoda(compatto_t* h, int n, int volte){
  compatto_t* tmp;
  compatto_t* curr;

  tmp = NULL;
  tmp = malloc(sizeof(compatto_t));
  if(tmp){
    tmp->next = NULL;
    tmp->n = n;
    tmp->occorrenze = volte;
    if(h){
      for(curr = h; curr->next; curr = curr->next);
      curr->next = tmp;
    }else{
      h = tmp;
    }
  }else{
    printf("Errore nell'allocazione del nodo\n");
  }  
  return h;
}