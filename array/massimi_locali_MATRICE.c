#include <stdio.h>

#define DIM 5

int main(){
	int m1[DIM][DIM];
	int i, j, h, k, isMax;

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			scanf("%d", &m1[i][j]);

		}
	}

	for(i = 0; i < DIM; i++){
			for(j = 0; j < DIM; j++){
				printf("%3d", m1[i][j]);

			}
			printf("\n");
	}

	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			isMax = 1;

			for(k = -1; k < 2 && isMax; k++){
				
				for(h = -1; h < 2 && isMax; h++){
				
					if(i + k > 0 && i + k < DIM && j + h > 0 && j + h < DIM)
				
						if(m1[i][j] < m1[i + k][j + h])
				
							isMax = 0;
				}
			}

			if(isMax)
				printf("%d: M[%d][%d] e' un massimo locale.\n", m1[i][j], i, j);

		}
	}

	return 0;
}