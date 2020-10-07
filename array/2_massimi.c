#include <stdio.h>

#define DIM 10
#define N_MAX 2

int main(){

	int num[DIM], i, j, max, indice_max;

	for(i = 0; i < DIM; i++){
		scanf("%d", &num[i]);
	} 


	for(i = 0; i < N_MAX; i++){
		indice_max = 0;
		max = num[indice_max];

		for(j = 0; j < DIM; j++){
		
			if(num[j] > max){
		
				max = num[j];
				indice_max = j;
			}
		}
		printf("Il massimo numero %d e':%d\n", i+1, max);
		num[indice_max] = 0;
	}

	return 0;
}