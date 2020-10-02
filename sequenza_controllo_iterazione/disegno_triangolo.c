#include <stdio.h>

int main(){
	int n, i, j, posizione, n_spazi;

	do{
		scanf("%d", &n);
	}while(n%2 != 0);

	i = 0;
	posizione = 0;
	n_spazi = (n-posizione)/2;

	while(posizione <= n){
		while(i < n_spazi){
			printf(" ");
			i = i + 1;
		}
		j = 0;
		while(j < posizione){
			printf("*");
			j = j + 1;
		}
		i = 0;
		while(i < n_spazi){
			printf(" ");
			i = i + 1;
		}
		i = 0;
		printf("\n");	

		posizione = posizione + 2;
		n_spazi = (n-posizione)/2;
	}


	return 0;
}