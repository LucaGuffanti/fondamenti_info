#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*inserisce un nuovo numero in coda alla lista*/
nodo_t* inserisciInCoda(nodo_t* lista, int num){
  nodo_t *prec;
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));
  if(tmp != NULL){
    tmp->next = NULL;
    tmp->num = num;
    if(lista == NULL)
      lista = tmp;
    else{
      for(prec=lista;prec->next!=NULL;prec=prec->next);
      prec->next = tmp;
    }
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

/*inserisce un nuovo numero in testa alla lista*/
nodo_t* inserisciInTesta(nodo_t* lista, int num){
  nodo_t *tmp;
  tmp = malloc(sizeof(nodo_t));
  if(tmp != NULL){
    tmp->num = num;
    tmp->next = lista;
    lista = tmp;    
  } else
      printf("Memoria esaurita!\n");
  return lista;
}

/*inserisce un numero nella lista rispettando un ordine crescente
 (affinchè l'ordine crescente sia preservato durante l'inserimenti, si assume che la lista di partenza sia ordinata in tale ordine)*/
nodo_t* inserisciInOrdine(nodo_t* testa, int n){
  if (!testa || testa->num > n)
    return inserisciInTesta(testa,n);
  testa->next = inserisciInOrdine(testa->next,n);
  return testa;
}

/*visualizza i numeri contenuti nella lista*/
void visualizza(nodo_t* lista){
  printf("lista: ");
  while(lista != NULL){
    printf("%d ", lista->num);
    lista = lista->next;
  }
  printf("\n");  
}

/*libera la memoria allocata per una lista*/
nodo_t* distruggiLista(nodo_t* lista){
  nodo_t* tmp;
  while(lista!= NULL){
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }
  return NULL;
}

/*restituisce 1 se un dato numero è presente nella lista altrimenti 0*/
int esisteElemento(nodo_t* lista, int num){
  for(;lista && lista->num!=num;lista=lista->next);
  return (lista != NULL);
}

/*rimuove dalla lista la prima occorrenza di un numero specificato come parametro, se presente*/
nodo_t* rimuovi(nodo_t* lista, int num){
  nodo_t *curr, *prec, *canc;
  int found;

  found=0;
  curr = lista;
  prec = NULL;      
  while(curr && ! found){
    if(curr->num==num){
      found=1;
      canc = curr;
      curr = curr->next;     
      if(prec!=NULL)
        prec->next = curr;
      else
        lista = curr;
      free(canc);
    }
    else{
      prec=curr;
      curr = curr->next;     
    }
  }
  return lista;

}

/*rimuove dalla lista tutte le occorrenzW di un numero specificato come parametro, se presente*/
nodo_t* rimuoviTutti(nodo_t* lista, int num){
  nodo_t *curr, *prec, *canc;

  curr = lista;
  prec = NULL;      
  while(curr){
    if(curr->num==num){
      canc = curr;
      curr = curr->next;     
      if(prec!=NULL)
        prec->next = curr;
      else
        lista = curr;
      free(canc);
    }
    else{
      prec=curr;
      curr = curr->next;     
    }
  }
  return lista;
}
