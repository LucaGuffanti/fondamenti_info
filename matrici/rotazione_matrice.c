#include <stdio.h>

#define DIM 5

int main(){

	int m1[DIM][DIM], m2[DIM][DIM], i, j;
/*Leggo gli elementi della prima matrice*/
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &m1[i][j]);
		}
	}
/*
	Costruisco la seconda matrice, come rotazione di 90 gradi in senso antiorario.
	Per farlo, si salva nella posizione (i, j) l'elemento in posizione(j, DIM - i).
	Il conto da 0 obbliga la sottrazione del valore 1 per evitare di uscire dalla porzione
	di memoria in cui sono contenuti gli elementi della matrice.

*/
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			m2[i][j] = m1[j][(DIM - 1) - i];
		}
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			printf("%3d ", m2[i][j]);
		}
		printf("\n");
	}


	return 0;
}