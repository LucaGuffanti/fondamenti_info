#include <stdio.h>

#define N 1

int main(){

	char l, next_l;

	scanf("%c", &l);
	while(l >= 'a' && l <= 'z'){
		next_l = l + N;

		/*
		  Gestisco "l'overflow dei char, sottraendo l'ultimo elemento dell'intervallo e sommando
		  quello che precede il primo, quindi l - 'z' + 'a' - 1;
		*/
		if(next_l > 'z'){
			next_l = next_l - 'z';
			next_l = next_l + 'a' - 1;
		}
		printf("%c\n", next_l);
		scanf(" %c", &l);
	}

	return 0;
}