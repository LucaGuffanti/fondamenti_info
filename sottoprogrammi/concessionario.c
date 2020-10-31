#include <stdio.h>

#define DIM_NAME 30
#define DIM_TARGA 7
#define MAX_AUTO 50
#define N_CONC 10

typedef struct{

	char nome[DIM_NAME + 1];
	char cogn[DIM_NAME + 1];
	char p_iva[DIM_NAME + 1];

} gestore_t;

typedef struct{

	char modello[DIM_NAME + 1];
	char targa[DIM_TARGA + 1];
	int mese;
	int anno;

} automobile_t;

typedef struct{

	int codice;
	gestore_t gestore;
	automobile_t lista[MAX_AUTO];
	int n_auto;

} concessionario_t;

void stampa(concessionario_t [], int, int aa);


int main(){

	concessionario_t concessionari[N_CONC];
	int i, j, anno;


	for(i = 0; i < N_CONC; i++){
		
		printf("Inserire codice concessionario:\n");
		scanf("%d", &concessionari[i].codice);
		
		printf("Inserire gestore:\n");
		scanf(" %s %s", concessionari[i].gestore.nome, concessionari[i].gestore.cogn);
		
		printf("Inserire numero di automobili:\n");
		scanf("%d", &concessionari[i].n_auto);
		
		for(j = 0; j < concessionari[i].n_auto; j++){
		
			printf("Macchina %d\n", j);
			
			printf("Inserire modello:\n");
			scanf("%s", concessionari[i].lista[j].modello);

			printf("Inserire targa:\n");
			scanf(" %s", concessionari[i].lista[j].targa);

			printf("Inserire mese e anno d'immatricolazione:\n");
			scanf(" %d %d", &concessionari[i].lista[i].mese, &concessionari[i].lista[j].anno);
		}
	}

	printf("Inserire l'anno da visualizzare\n");
	scanf(" %d", &anno);

	stampa(concessionari, N_CONC, anno);

	return 0;
}

void stampa(concessionario_t conc[], int dim_l_conc, int aa){

	int i, j, presente;
	
	for(i = 0; i < dim_l_conc; i++){
	
		printf("Conc. %d, codice %d: gestore %s %s\n", i, conc[i].codice, conc[i].gestore.nome, conc[i].gestore.cogn);
		printf("Immatricolazioni %d\n", aa);
	
		for(j = 0, presente = 0; j < conc[i].n_auto; j++){
	
			if(conc[i].lista[j].anno == aa){
				presente = 1;
				printf("* mese %d: %s, %s\n", conc[i].lista[j].anno, conc[i].lista[j].modello, conc[i].lista[j].targa);
			}

			if(!presente){
				printf("NESSUNA IMMATRICOLAZIONE\n");
			}
		}
	}
}