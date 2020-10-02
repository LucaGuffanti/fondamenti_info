#include <stdio.h>

#define NUM 5
int main(){
	int numero, max, i;

	scanf("%d", &numero);

	max = numero;
	i = 1;

	while(i < NUM){
		scanf("%d", &numero);
		if(numero > max)
			max = numero;

		i++;
	} 

	printf("%d e' il numero massimo.\n", max);


	return 0;
}