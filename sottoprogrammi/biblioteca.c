#include <stdio.h>

#define N_LIBRI 1000
#define MAX_STR 100
#define N_BIB 10

typedef struct{

	char autore[MAX_STR + 1];
	char titolo[MAX_STR + 1];
	float prezzo;
	int pagine;

} t_libro;

typedef struct{

	t_libro libri[N_LIBRI];
	int n_libri;
	char nome[MAX_STR + 1];
	char indirizzo[MAX_STR + 1];

} t_biblioteca;

void contapagine(t_biblioteca [], int, int []);

int main(){

	t_biblioteca bib[N_BIB];
	int ris[N_BIB];
	int i, j;

	for(i = 0; i < N_BIB; i++){
		printf("Nome biblioteca\n");
		scanf("%s", bib[i].nome);

		printf("Indirizzo biblioteca\n");
		scanf("%s", bib[i].indirizzo);

		printf("Numero di libri\n");
		scanf("%d", &bib[i].n_libri);

		for(j = 0; j < bib[i].n_libri; j++){

			printf("Libro %d\n", j);

			printf("Autore\n");
			scanf("%s", bib[i].libri[j].autore);

			printf("Titolo\n");
			scanf("%s", bib[i].libri[j].titolo);

			printf("Numero di pagine\n");
			scanf("%d", &bib[i].libri[i].pagine);

			printf("Prezzo\n");
			scanf("%f", &bib[i].libri[i].prezzo);
		}
	}

	contapagine(bib, N_BIB, ris);

	for(i = 0; i < N_BIB; i++){
		printf("Nella biblioteca %d ci sono %d pagine\n", i, ris[i]);
	}



	return 0;
}

void contapagine(t_biblioteca bib[], int dim, int ris[]){

	int i, j, somma;
	for(i = 0, somma = 0; i < dim; i++){
		for(j = 0; j < bib[i].n_libri; j++){
			somma = somma + bib[i].libri[j].pagine;
		}
	}
}