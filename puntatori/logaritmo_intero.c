#include <stdio.h>

int potenza(int, int);

int logaritmo_intero(int, int, int *);

int main(){

	int num, grado, log, precisa;

	scanf("%d%d", &num, &grado);

	precisa = logaritmo_intero(num, grado, &log);

	printf("radice %d di %d: %d -> %d\n", grado, num, log, precisa);

return 0;
}

int potenza(int base, int esponente){

	int pot, i;

	pot = 1;

	for(i = 0; i < esponente; i++){
		pot = pot * base;
	}

	return pot;
}

int logaritmo_intero(int num, int base, int *log){
	int i;

	i = 0;
	while(potenza(base, i) <= num){
		i++;
	}

	i--;
	*log = i;

	return potenza(base, i) == num;
}