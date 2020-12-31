#ifndef LISTA_H
#define LISTA_H

/*definizione della struttura per la lista concatenata*/
typedef struct nodo_{
  int num;
  struct nodo_ *next;
} nodo_t;

/*prototipi delle funzioni*/
nodo_t* inserisciInCoda(nodo_t*, int);
nodo_t* inserisciInTesta(nodo_t*, int);
nodo_t* inserisciInOrdine(nodo_t* testa, int n);
nodo_t* rimuovi(nodo_t*, int);
nodo_t* rimuoviTutti(nodo_t*, int);
void visualizza(nodo_t*);
nodo_t* distruggiLista(nodo_t*);
int esisteElemento(nodo_t*, int);

#endif
