#include <stdio.h>
#include <string.h>

#define TITOLO 100
#define MAXAUTORI 10
#define INFOAUTORE 50

typedef struct{
	
	char titolo[TITOLO + 1];
	char nome[INFOAUTORE + 1];
	char cogn[INFOAUTORE + 1];
	char universita[INFOAUTORE + 1];
	char email[INFOAUTORE + 1];

} autore_t;

typedef struct{

	autore_t autore;

	autore_t affiliati[MAXAUTORI];
	int nAutori;

} pubblicazione_t;

int contaPubblicazioni(pubblicazione_t p[], int pdim, char uni[INFOAUTORE + 1]){
	int i, j, contaTot, contaAffiliati;

	for(i = 0, contaTot = 0; i < pdim; i++){
		for(j = 0, contaAffiliati = 0; j < p[i].nAutori; j++){
			if(!strcmp(uni, p[i].affiliati[j].universita)){
				contaAffiliati++;
			}
		}
		if(contaAffiliati >= p[i].nAutori/2){
			contaTot++;
		}
	}

	return contaTot;
}
