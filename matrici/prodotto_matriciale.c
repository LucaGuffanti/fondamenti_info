#include <stdio.h>

#define DIM 4

int main(){
	int a[DIM][DIM], b[DIM][DIM], m[DIM][DIM], i, j, k;

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &b[i][j]);
		}
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			/*Il terzo ciclo è la sommatoria, che esprime il prodotto scalare.*/
			for(k = 0, m[i][j] = 0; k < DIM; k++){
				m[i][j] = m[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			printf("%3d ",m[i][j]);
		}
		printf("\n");
	}


	return 0;
}