#include <stdio.h>

int main(){

	int num, intervallo, i, somma, triangolare, n;
	scanf("%d", &num);

	somma = 0;
	i = 1;
	triangolare = 0;
	while(i <= num && !triangolare){
		somma = somma + i;
		triangolare = somma == num;
		n = i;
		i = i + 1;
		
	}

	if(triangolare)
		printf("%d e' triangolare per N = %d.\n", num, n);
	else
		printf("Numero non triangolare.\n");
	return 0;
}