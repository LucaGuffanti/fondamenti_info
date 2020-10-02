#include <stdio.h>

#define BASE 2

int main(){

	int numero, bit;
	scanf("%d", &numero);

	while(numero > 0){
		bit = numero%BASE;
		numero = numero/BASE;
		printf("%d", bit);
	}

	printf("\n");

	return 0;
}