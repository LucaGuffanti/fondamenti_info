#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
  int n;
  struct nodo_* next;
} nodo_t;


nodo_t* delfromlist(nodo_t*, int);

nodo_t* delfromlist(nodo_t* h, int x){
 nodo_t* tmp;
 nodo_t* curr;
 int presente;
 
 for(curr = h; curr; curr = curr->next){
   for(tmp = curr, presente = 0; tmp && presente < x; tmp->next){
     if(tmp->n == x)
       presente++;    
   }
   if(presente >= x){
      h = delete(h, curr->n);
   }
 }
  free(tmp);
  free(curr);
  return h;
}