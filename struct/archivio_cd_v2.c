#include <stdio.h>
#include <string.h>

#define DIM_ARCHIVIO 100
#define SDIM 30

typedef struct{

	int ore, min, sec;

}durata_t;

typedef struct{
	//campi della struct
	char titolo[SDIM + 1];
	char autore[SDIM + 1];

	int anno;
	durata_t durata;
	int ntracce;

	float prezzo;

}cd_t;


int main(){

	cd_t cd[DIM_ARCHIVIO]; //array di strutture
	
	int n_cd;
	int i, max_i, j, conto, conto_max;
	
	durata_t max_d;
	
	char[SDIM + 1];



	scanf("%d", &n_cd); //si assume un corretto inserimento dei dati

	for(i = 0; i < n_cd; i++){

		scanf(" %[^\n]", cd[i].titolo);
		scanf(" %[^\n]", cd[i].autore);
		scanf("%d", &cd[i].anno);
		scanf("%d%d%d", &cd[i].durata.ore, &cd[i].durata.min, &cd[i].durata.sec);
		scanf("%d", &cd[i].ntracce);
		scanf("%f", &cd[i].prezzo);
	}

	max_i = 0;

	for(i = 1; i < n_cd; i++){
		if(cd[i].durata.ore > cd[max_i].durata.ore ||
		   (cd[i].durata.ore == cd[max_i].durata.ore && cd[i].durata.min > cd[max_i].durata.min) ||
		   (cd[i].durata.ore == cd[max_i].durata.ore && cd[i].durata.min == cd[max_i].durata.min && 
		   	cd[i].durata.sec > cd[max_i].durata.sec))
			max_i = i;
	}

	printf("Cd con durata massima: %s\n", cd[max_i].titolo);

	max_d = cd[0].durata;

	for(i = 1; i < n_cd; i++){
		
		if(cd[i].durata.ore > max_d.ore
		   || (cd[i].durata.ore == max_d.ore && cd[i].durata.min > max_d.ore)
		   || (cd[i].durata.ore == max_d.ore && cd[i].durata.min == max_d.ore && cd[i].durata.sec > max_d.sec)){
			max_d = cd[i].durata;
		}
	}

	for(i = 0; i < n_cd; i++){
		
		if(cd[i].durata.ore == max_d.ore && cd[i].durata.min == max_d.min && cd[i].durata.sec == max_d.sec){

			printf("%s\n", cd[i].titolo);
		}
	}

	scanf("%[^\n]", autore);

	for(i = 0; i < n_cd; i++){
		if(!strcmp(autore, cd[i].autore)) //oppure strcmp(autore, cd[i].autore) == 0
			printf("%s\n", cd[i].titolo);
	}

	conto = 0;
	conto_max = 0;
	k_max = 0;

	for(i = 0; i < n_cd; i++){
		for(j = i; j < n_cd; j++){
			if(!strcmp(cd[i].autore, cd[j].autore)){
				conto++;
			}
		}

		if(conto > conto_max){
			conto_max = conto;
			strcpy(autore, cd[i].autore); //arrivo, partenza
		}

	}

	printf("%s\n", autore);
	return 0;

}