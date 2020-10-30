#include <stdio.h>

#define MAXDIM 10

int main(){


	int m[MAXDIM][MAXDIM];
	int i, j, somma, dim;

	do{
		printf("Inserire la dimensione del triangolo\n");
		scanf("%d", &dim);
	}while(dim > MAXDIM || dim < 1);

	for(i = 0; i < MAXDIM; i++){
		for(j = 0; j < MAXDIM; j++){
			m[i][j] = 0;
		}
	}

	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			if(j == 0){
				m[i][j] = 1;
			}else{
				if(i > 0){
					m[i][j] += m[i - 1][j - 1] + m[i - 1][j]; 
				}
			}
		}
	}


	for(i = 0; i < dim; i++){
		for(j = 0; j < dim; j++){
			if(m[i][j] != 0){
				printf("%2d ", m[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}