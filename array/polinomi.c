#include <stdio.h>

#define DIM 9

int main(){

	int polinomio[DIM], i, j, incognita, soluzione, potenza, grado;

	scanf("%d", &grado);

	while(grado < 0 || grado > 8){
		printf("Grado da 0 a 8.\n");
		scanf("%d", &grado);
	}

	for(i = 0; i <= grado; i++){
		printf("Coefficiente di x^%d:", i);
		scanf("%d", &polinomio[i]);
	}

	scanf("%d", &incognita);

	potenza = incognita;
	soluzione = polinomio[0];

	for(i = 1; i <= grado; i++){
		for(j = 1; j < i; j++){

			potenza = potenza * incognita;
		}

		soluzione = soluzione +(polinomio[i] * potenza);
		potenza = incognita;
	}

	printf("%d\n", soluzione);

	return 0;
}