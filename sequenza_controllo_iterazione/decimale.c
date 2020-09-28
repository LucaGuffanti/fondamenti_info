#include<stdio.h>

int main(){
	float numero, decimale;
   	int intero;

	scanf("%f", &numero);
	intero = numero;
	decimale = numero - intero;
	printf("%d\n%f\n",intero, decimale);
	return 0;
}