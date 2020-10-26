#include <stdio.h>

int main(){

	int a, b;
	int *c, *d, *e;

	a = 2;
	b = 3;

	c = &a; /*In c manteniamo l'indirizzo di a*/	
	
	d = c; /*alla variabile d associamo il valore di c, quindi l'indirizzo di a*/

	b = *c; /*a b si assegna il valore della variabile puntata da c, quindi 2*/

	*c = 4; /*alla variabile puntata da c si scrive il valore 4*/

	/*b = c; errore: c è un puntatore, e non si può assegnare un indirizzo ad una variabile int*/

	/*c = b; anche questo è un errore: c punterà ad un indirizzo a caso*/

	/* *e = b; andiamo a scrivere nella riga a caso il contenuto di b. cosa che causerà una 
			segmentation fault, poiché e non è inizializzato e punta ad una cella a caso della memoria.*/
	e = &b; /*questa invece è un'assegnamento corretto*/

	*e = *c; /*alla variabile puntata da e assegno il valore della variabile puntata da c*/

	scanf("%d", e); /*salvo nella variabile b il valore ottenuto dalla scanf*/

	printf("%d %d %p %p %p\n",a, b, c, d, e);

	/*
	come capiamo che il puntatore non punta a nulla?
	*/

	e = NULL /*così e non punta a nulla*/

	/*con printf("%d", *e) avremmo un errore
	possiamo quindi fare così
	*/

	if(e != NULL)
		printf("%d\n", *e);

	return 0;

}