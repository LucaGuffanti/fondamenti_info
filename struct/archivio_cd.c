#include <stdio.h>

#define DIM_ARCHIVIO 100
#define SDIM 30

typedef struct{

	char titolo[SDIM + 1];
	char autore[SDIM + 1];

	int anno;
	int ore, min, sec;
	int ntracce;

	float prezzo;

}cd_t;


int main(){

	cd_t cd[DIM_ARCHIVIO]; //array di strutture
	int n_cd;
	int i, max;

	scanf("%d", &n_cd); //si assume un corretto inserimento dei dati

	for(i = 0; i < n_cd; i++){

		scanf(" %[^\n]", cd[i].titolo);
		scanf(" %s", cd[i].autore);
		scanf("%d", &cd[i].anno);
		scanf("%d%d%d", &cd[i].ore, &cd[i].min, &cd[i].sec);
		scanf("%d", &cd[i].ntracce);
		scanf("%f", &cd[i].prezzo);
	}

	//estraggo il monte ore massimo

	
	for(i = 1, max = 0; i < n_cd; i++){

		if(cd[i].ore > cd[max].ore || cd[i].min > cd[max].min || cd[i].sec > cd[max].sec){

			max = i;
		}
	}

	//stampo il risultato richiesto dal problema

	printf("Titolo : %s\n", cd[max].titolo);
	printf("Artista: %s\n", cd[max].autore);
	printf("Anno   : %d\n", cd[max].anno);
	printf("%d ore %d min %d sec\n", cd[max].ore, cd[max].min, cd[max]. sec);
	printf("Tracce : %d\n", cd[max].ntracce);
	printf("Prezzo :%f euro\n", cd[max].prezzo);


	return 0;
}