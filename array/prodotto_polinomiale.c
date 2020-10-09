/*

	es (1 + x)(1 + x)

*/

#include <stdio.h>

#define DIM 9

int main(){

	int polinomio1[DIM], polinomio2[DIM], prodotto[(2*DIM) - 1];
	int grado1, grado2, gradoProd, i, j;

	scanf("%d%d", &grado1, &grado2);

	while((grado1 < 0 || grado1 > DIM - 1) || (grado2 < 0 || grado2 > DIM - 1)){
		printf("Grado Errato\n");
		scanf("%d%d", &grado1, &grado2);
	}

	gradoProd = grado1 + grado2;

	for(i = 0; i <= grado1; i++){
		printf("x^%d * ", i);
		scanf("%d", &polinomio1[i]);
	}


	for(i = 0; i <= grado2; i++){
		printf("x^%d * ", i);
		scanf("%d", &polinomio2[i]);
	}


	for(i = 0; i <= gradoProd; i++){
		prodotto[i] = 0;
	}

	for(i = 0; i <= grado1; i++){
		for(j = 0; j <= grado2; j++){
			if(i == 0 || j == 0){
				prodotto[i + j] = prodotto[i + j] + (polinomio1[i] * polinomio2[j]);
			}else{
				prodotto[i + j] = prodotto[i + j] + (polinomio1[i] * polinomio2[j]);
			}
		}
	}

	for(i = 0; i <= gradoProd; i++){
		if(prodotto[i])
			printf("%d*x^%d\n", prodotto[i], i);
	}

	return 0;
}
