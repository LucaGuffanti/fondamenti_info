#include <stdio.h>

#define DIM 4

int main(){

	/*

		1 0 0 0
		0 1 0 0
		0 0 1 0
		0 0 0 1
	
		è una matrice identità 4x4. la diag. princ. ha i == j.
	*/

	int m[DIM][DIM], i, j, ident;

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &m[i][j]);
		}
	}

	for(i = 0, ident = 1; i < DIM && ident; i++){
		for(j = 0; j < DIM && ident; j++){
			if((i == j && m[i][j] != 1) || (i != j && m[i][j] != 0)){
				ident = 0;
			}
		}
	}

	printf("%d\n", ident);


	return 0;
} 