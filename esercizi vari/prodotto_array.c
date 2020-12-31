#include <stdio.h>
#define DIM 25

int main(int argc, char* argv[]){

	int prod, i, j, k, maxProd;
	int v[DIM];

	for(i = 0; i < DIM; i++){
		scanf("%d", &v[i]);
	}

	prod = maxProd = 0;
	for(i = 0; i < DIM; i++){
		for(j = i+1; j < DIM; j++){
			for(k = j+1; k < DIM; k++){
				prod = v[i]*v[j]*v[k];
				if(prod > maxProd){
					maxProd = prod;
				}
			}
		}
	}

	printf("massimo: %d\n", maxProd);

	return 0;
}