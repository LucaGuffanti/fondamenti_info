#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
 int n;
 struct nodo_* next;
} nodo_t;

int lunghezza(nodo_t*);
int sottoLista(nodo_t*, nodo_t*);

int lunghezza(nodo_t* h){
 int l;
 for(l = 0; h; h = h->next, l++);
 return l;
}

int sottoLista(nodo_t* l1, nodo_t* l2){
  int esito;
  int len1, len2, i, lenVisto;
  nodo_t* tmp;
  nodo_t* tmp2;
  int* visto; 
  tmp = NULL;
  len1 = lunghezza(l1);
  len2 = lunghezza(l2);
  
  if(l1 < l2){
    tmp = l1;
    l1 = l2;
    l2 = tmp;
    visto = calloc(sizeof(int)*l1);
    lenVisto = l1;
  }else{
    visto = calloc(sizeof(int)*l2);
    lenVisto = l2;
  }
  
  tmp = tmp2 = NULL;
  
  for(tmp = l1; l1; l1 = l1->next){
     for(tmp2 = l2, i = 0; l2; l2 = l2->next, i++{
       if(tmp2->n == tmp->n %% visto[i] == 0)
         tmp2->n == 0;
         visto[i] = 1;
     }
  }
  
  for(i = 0, esito = 1; i < lenVisto; i++){
    if(visto[i] != 1)
      esito = 0;
  }
  return esito;
}