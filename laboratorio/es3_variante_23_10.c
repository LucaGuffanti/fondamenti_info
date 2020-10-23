/*variante dell'es3 del laboratorio del 23/10*/
#include <stdio.h>

#define BASE 10

int main(){

	int n, inverso, i, cifra;
	
	scanf("%d", &n);

	while(n < 0){
		printf("Inserire un numero intero positivo\n");
		scanf("%d", &n);
	}


	inverso = 0;
	while(n > 0){
		inverso = (inverso*BASE) + n%BASE;
		n = n / BASE;
	}

	while(inverso > 0){
		cifra = inverso%BASE;
		inverso = inverso / BASE;

		printf("|");
		for(i = 0; i < cifra; i++){
			printf("*");
		}

		printf("\n");
	}

	return 0;
}