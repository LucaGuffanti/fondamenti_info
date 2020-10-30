/*es3 del laboratorio del 23/10*/

#include <stdio.h>

#define BASE 10

int main(){

	int n, i, cifra;

	scanf("%d", &n);

	while(n < 0){
		printf("Inserire un numero intero positivo\n");
		scanf("%d", &n);
	}

	while(n > 0){
		cifra = n%BASE;
		n = n/BASE;

		printf("|");
		for(i = 0; i < cifra; i++){
			printf("*");
		}

		printf("\n");
	}



	return 0;
}