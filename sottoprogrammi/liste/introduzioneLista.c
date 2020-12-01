#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
	nodo_t *testa;

	testa = NULL;

	testa = inserisciInCoda(testa, 1);
	testa = inserisciInCoda(testa, 2);
	testa = inserisciInCoda(testa, 3);
	testa = inserisciInCoda(testa, 4);

	visualizza(testa);

	testa = distruggiLista(testa);

	return 0;
}