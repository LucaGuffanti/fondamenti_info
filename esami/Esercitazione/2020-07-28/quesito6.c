#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int indice;
	struct nodo_ *next;
} nodo_t;

nodo_t* analisiSoglia(int [], int, int);
nodo_t* inserisciInCoda(nodo_t*, int);

nodo_t* analisiSoglia(int arr[], int dim, int soglia){
	nodo_t *h;
	int i;

	h = NULL;

	for(i = 0; i < dim; i++){
		if(arr[i] > soglia*soglia){
			h = inserisciInCoda(h, i);
		}
	}
	return h;
}

nodo_t* inserisciInCoda(nodo_t *h, int num){
	nodo_t *tmp;
	nodo_t *curr;

	tmp = malloc(sizeof(nodo_t));
	if(tmp){
		tmp->next = NULL;
		tmp->indice = num;

		if(h){
			for(curr = h; curr->next; curr = curr->next);
			curr->next = tmp;
		}else{
			h = tmp;
		}
	}else{
		printf("Errore nell'allocazione\n");
	}

	return h;
}