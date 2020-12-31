#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int sommaRicorsiva(nodo_t*);

int main(int argc, char* argv[]){

	return 0;
}

int sommaRicorsiva(nodo_t *h){
	if(h){
		h->num += sommaRicorsiva(h->next);
		return h->num;
	}else{
		return 0;
	}
}