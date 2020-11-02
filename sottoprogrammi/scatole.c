#include <stdio.h>

#define N_OGGETTI 100
#define N_SCATOLE 10
#define MAX_STR 100
#define PESO_CONTAINER 100

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

		scanf("%s", sc[i].descrizione);
		scanf("%d", &sc[i].codice);
		scanf("%d", &sc[i].n_oggetti);

		for(j = 0; j < sc[i].n_oggetti; j++){

			scanf("%s", sc[i].oggetti[j].descrizione);
			scanf("%d", &sc[i].oggetti[j].codice);
			scanf("%d", &sc[i].oggetti[j].quanti);
			scanf("%f", &sc[i].oggetti[j].peso_per_unita);

		}
	}

	printf("Sono caricabili %d scatole\n", carica_container(sc, N_SCATOLE, PESO_CONTAINER));

	return 0;
}

int carica_container(t_scatola sc[], int dim, float peso){

	int i, j, conta, caricabile;
	float somma_oggetti;

	for(i = 0, caricabile = 1, conta = 0; i < dim && caricabile; i++){

		for(j = 0, caricabile = 1, somma_oggetti = 0; j < sc[i].n_oggetti && caricabile; j++){
			somma_oggetti = somma_oggetti + (sc[i].oggetti[j].quanti * sc[i].oggetti[j].peso_per_unita);
		}

		peso = peso - somma_oggetti;
		caricabile = peso <= 0;

		if(caricabile){
			conta++;
		}
	}

	return conta;
}
