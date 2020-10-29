#include <stdio.h>

#define MAXS 50

int main(){

	int v[MAXS], *p2, l;

	p2 = v; /*p2 contiene l'indirizzo della base dell'array*/

	p2 = p2 + 2; /*punterò 2 celle in avanti, come v[2]*/

	l = p2 - v /*questo mi porterà l a 2*/

	/*Noi non possiamo passare un INTERO array alla funzione.
	poiché l'array rappresenta un puntatore costante
	-> gli array vengono passati solo per indirizzo. la funzione avrà un
	collegamento diretto con la memoria del chiamante, e quindi modificherà l'array*/

	
	return 0;
}