/*
La trasposta è una matrice che che è del tipo a(jxi) partendo da una a(ixj)
una matrice la cui trasposta è pari a quella iniziale si dice simmetrica
*/

#include <stdio.h>

#define DIM 4

int main(){
	int m[DIM][DIM], i, j, simm;

	for(i = 0; i < DIM; i++){
		for(j = 0; j <DIM; j++){
			scanf("%d", &m[i][j]);
		}
	}

	for(i = 0, simm = 1; i < DIM && simm; i++){
		for(j = 0; j < DIM && simm; j++){
			if(m[i][j] != m[j][i])
				simm = 0;
		}
	}

	printf("%d\n", simm);

	return 0;
}