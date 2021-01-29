#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_* next;
} nodo_t;

nodo_t* ruotaDestra(nodo_t*);
nodo_t* ruotaSinistra(nodo_t*);
nodo_t* hubRuota(nodo_t*, int);

nodo_t* hubRuota(nodo_t* h, int dir){
  if(!h)
   return NULL;
  else if(!(h->next))
   return h;
  else if(dir == 0)
   return ruotaSinistra(h);
  else if(dir == 1)
   retrun ruotaDestra(h);
}


nodo_t* ruotaDestra(nodo_t* h){
 /*tolgo l'ultimo elemento e lo metto come primo*/
 nodo_t* tmp1;
 nodo_t* tmp2;
 
 for(tmp1 = h; (tmp1->next)->next != NULL; tmp1 = tmp1->next);
 tmp2 = (tmp1)->next;
 tmp1->next = (tmp1->next)->next;
 h = push(h, tmp2->n);

 free(tmp2);
 return h;
}

nodo_t* ruotaSinistra(nodo_t* h){
 /*tolgo il primo elemento e lo metto come ultimo*/
 nodo_t* tmp;
 tmp = h;
 h = pop(h);
 h = append(h, tmp->n);
 free(tmp);
 return h;
}