#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define BASE 10

typedef struct nodo_{
	int n;
	struct nodo_ *next;
} nodo_t;

nodo_t* int2List(int);


int main(int argc, char *argv[]){
	nodo_t *h;

	h = NULL;

	if(argc == 2){
		h = int2List(atoi(argv[1]));
		visualizza(h);
		h = distruggiLista(h);

	}else{
		printf("Errore negli argomenti\n");
	}


	return 0;
}

nodo_t* int2List(int num){

	int cifra, i, negativo;
	nodo_t *h;

	h = NULL;

	negativo = num < 0;
	if(negativo)
		num = -num;
	while(num > 0){
		cifra = num%BASE;
		
		if(negativo){
			for(i = 0; i < cifra; i++){
				h = inserisciInTesta(h, cifra);
			}
		}else{
			for(i = 0; i < cifra; i++){
				h = inserisciInCoda(h, cifra);
			}
		}
		num = num/BASE;
	}

	return h;

}