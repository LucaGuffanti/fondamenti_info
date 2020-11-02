#include <stdio.h>

#define N_OGGETTI 100
#define N_SCATOLE 10
#define MAX_STR 100
#define PESO_CONTAINER 100.0

typedef struct{

	char descrizione[MAX_STR + 1];
	float peso_per_unita;
	int quanti;
	int codice;
} t_oggetto;

typedef struct{

	t_oggetto oggetti[N_OGGETTI];
	int n_oggetti;
	char descrizione[MAX_STR + 1];
	int codice;

} t_scatola;

int carica_container(t_scatola [], int, float);

int main(){

	t_scatola sc[N_SCATOLE];
	int i, j;

	for(i = 0; i < N_SCATOLE; i++){
		scanf("%d %s %d", &sc[i].codice, sc[i].descrizione, &sc[i].n_oggetti);

		for(j = 0; j < sc[i].n_oggetti; j++){
			scanf(" %s %f %d %d", sc[i].oggetti[j].descrizione, &sc[i].oggetti[j].peso_per_unita, &sc[i].oggetti[j].quanti, &sc[i].oggetti[j].codice);
		}
	}

	printf("%d\n", carica_container(sc, N_SCATOLE, PESO_CONTAINER)s);

	return 0;
}

int carica_container(t_scatola sc[], int dim, float peso){

	int i, j;

	for(i = 0; i < dim && peso > 0; i++){

		for(j = 0; j < sc[i].n_oggetti && peso >= 0; j++){
			peso = peso - sc[i].oggetti[j].quanti * sc[i].oggetti[j].peso_per_unita;
		}
	}

	if(peso < 0){
		i--;
	}

	return i;

}