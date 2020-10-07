#include <stdio.h>

#define DIM 10
#define MINIMO 0
#define MASSIMO 9

int main(){

	int numeri[DIM], valore, i, j;

	for(i = 0; i < DIM; i++){
		numeri[i] = 0;
	}

	scanf("%d", &valore);

	while(valore >= MINIMO && valore <= MASSIMO){
		numeri[valore] = numeri[valore] + 1;
		scanf("%d", &valore);
	}

	for(i = 0; i < DIM; i++){
		printf("%d   ", i);
		for(j = 0; j < numeri[i]; j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}