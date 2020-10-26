#include <stdio.h>

int potenza(int, int);

int radice_intera(int, int, int *);

int main(){

	int num, grado, radice, precisa;

	scanf("%d%d", &num, &grado);

	precisa = radice_intera(num, grado, &radice);

	printf("radice %d di %d: %d -> %d\n", grado, num, radice, precisa);

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

int radice_intera(int base, int grado, int *radice){

	int i;

	i = 1;

	while(potenza(i, grado) <= base){
		i++;
	}
	i--;
	*radice = i;

	return potenza(i, grado) == base;

}