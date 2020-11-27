#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int n;
	nodo_ *next;
} nodo_t;

nodo_t* riferimentoDaCoda(nodo_t *, int);

nodo_t* riferimentoDaCoda(nodo_t *h, int k){

	nodo_t *tmp;
	int lunghezza;
	int passi;

	/*calcolo della lunghezza della lista*/
	for(tmp = h, lunghezza = 0; tmp; lunghezza++, tmp = tmp->next);

	/*ricerca del valore d'interesse*/
	passi = lunghezza - k ;

	for(; h && passi > 0; h = h->next, passi--);

	if(passi < 0){
		h = NULL;
	}
	return h;
}