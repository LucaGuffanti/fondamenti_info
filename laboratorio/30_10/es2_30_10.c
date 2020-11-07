#include <stdio.h>
#include <string.h> 

#define STRDIM 30
#define DIM 5

typedef struct{

	char ita[STRDIM + 1];
	char eng[STRDIM + 1];

} parola_t;

int main(){

	parola_t lista[DIM];
	int i, conta, j, imax, presenze;

	for(i = 0; i < DIM; i++){
		scanf("%s %s", lista[i].ita, lista[i].eng);
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			if(!strcmp(lista[i].ita, lista[j].eng)){
				printf("%s %s * %s %s\n", lista[i].ita, lista[i].eng, lista[j].ita, lista[j].eng);
			}
		}
	}

	imax = 0;
	presenze = 0;

	for(i = 0; i < DIM; i++){
		for(j = i, conta = 0; j < DIM; j++){
			if(!strcmp(lista[i].ita, lista[j].ita))
				conta++;
		}

		if(conta > presenze){
			presenze = conta;
			imax = i;
		}

	}

	for(i = 0; i < DIM; i++){
		if(!strcmp(lista[imax].ita, lista[i].ita)){
			printf("%s %s\n", lista[i].ita, lista[i].eng);
		}
	}

	return 0;
}