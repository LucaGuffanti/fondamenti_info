#include <stdio.h>

#define DIM 6

typedef struct{

	int m[DIM][DIM];
	int nrighe, ncolonne;

} matrice_t;

int main(){

	matrice_t a, b, somma;
	int i, j, k;


	do{
		scanf("%d%d", &a.nrighe, &a.ncolonne);
	}while((a.nrighe <= 0 || a.nrighe >= DIM) || (a.ncolonne <= 0 || a.ncolonne >= DIM));

	do{
		scanf("%d%d", &b.nrighe, &b.ncolonne);
	}while((b.nrighe <= 0 || b.nrighe >= DIM) || (b.ncolonne <= 0 || b.ncolonne >= DIM));


	for(i = 0; i < a.nrighe; i++){
		for(j = 0; j < a.ncolonne; j++){
			
			scanf("%d", &a.m[i][j]);
		}
	}



	for(i = 0; i < b.nrighe; i++){
		for(j = 0; j < b.ncolonne; j++){
			
			scanf("%d", &b.m[i][j]);
		}
	}

	if(a.ncolonne == b.nrighe){
		somma.nrighe = a.nrighe;
		somma.ncolonne = b.ncolonne;

		for(i = 0; i < somma.nrighe; i++){
			for(j = 0; j < somma.ncolonne; j++){
				for(k = 0, somma.m[i][j] = 0; k < a.ncolonne; k++){
					somma.m[i][j] = somma.m[i][j] + (a.m[i][k] * b.m[k][j]);
				}
			}
		}


		for(i = 0; i < somma.nrighe; i++){
			for(j = 0; j < somma.ncolonne; j++){
				printf("%d ", somma.m[i][j]);
			}

			printf("\n");
		}

	}else{
		printf("Prodotto non calcolabile\n");
	}
	return 0;
}