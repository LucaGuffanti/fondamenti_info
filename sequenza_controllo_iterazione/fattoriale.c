#include <stdio.h>

int main(){
	int n, fatt, i;

	scanf("%d", &n);

/*
Questo se non volessi il messaggio di errore
	do{
		scanf("%d", &n);
	}while(n < 0);


Con il ciclo sotto si vuole scrivere l'errore 1 O PIU' VOLTE.
*/
	while(n < 0){
		printf("Errore.\n");
		scanf("%d", &n);
	}
/*
	!CON INCREMENTO!	
	fatt = 1;
	i = 2;

	while(i <= n){
		fatt = fatt * i;
		i = i + 1;
	}
	

	!CON DECREMENTO!
*/

	fatt = 1;
	while(n > 1){
		fatt = fatt * n;
		n = n - 1;
	}
	printf("%d\n", fatt);
	return 0;

}