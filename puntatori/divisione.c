#include <stdio.h>

void divisione(int, int, int *, int *);

int main(){

	int num, divisore, risultato, resto;

	scanf("%d", &num);
	
	for(divisore = 2, resto = 1;  resto != 0; divisore++){
		divisione(num, divisore, &risultato, &resto);
	}

	divisore--;

	printf("%d/%d = %d + %d/%d\n",num, divisore, risultato, resto, divisore);

	return 0;
}

void divisione(int dividendo, int divisore, int *risultato, int *resto){
	
	*risultato = dividendo / divisore;
	*resto = dividendo % divisore;
}