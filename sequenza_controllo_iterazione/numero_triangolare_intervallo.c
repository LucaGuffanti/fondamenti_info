#include <stdio.h>

int main(){
	int k, n, somma, i, j, triangolare;
	
	/*
	scanf("%d%d", &k, &N);
	
	i = 1;
	while(i <= k){
		j = 1;
		while(j <= N){
			somma = somma + j;
			j = j + 1;
		}
		
		if(somma == i){
			printf("%d e' un numero triangolare per N = %d\n", i, N);
		}

		somma = 0;
		i = i + 1;
	}
	*/

	scanf("%d", &k);
	i = 1;
	while(i <= k){
		j = 1;
		somma = 0;
		triangolare = 0;
		while(j <= k && !triangolare){
			somma = somma + j;
			triangolare = somma == i;
			n = j;
			j = j + 1;
		}
		if(triangolare){
			printf("%5d e' triangolare per N = %5d.\n", i, n);
		}

		i = i + 1;
	}
	return 0;
}