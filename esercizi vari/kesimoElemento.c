#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
  int num;
  struct nodo_* next;
} nodo_t;

int lunghezza(nodo_t*);
nodo_t* riferimentoK(nodo_t*, int);

int lunghezza(nodo_t* h){
  int l;
  for(l = 0; h; h = h->next, l++);
  return l;
}

nodo_t* riferimentoK(nodo_t* h, int k){
 int percorso;
 int i;
 percorso = lunghezza(h) - k; 
 
 if(percorso < 0)
   return NULL;
 else
  for(i = 0; h && i < percorso; i++, h = h->next);

 return h;
}

/*1 2 3 4 5 6 7 8 9, k = 15
                   , lunghezza = 9
                     i = 0 -> 9-3 = 6
  0 1 2 3 4 5 6 7 8
  0 1 2 3 4 5 6
*/