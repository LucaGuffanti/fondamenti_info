#include <stdio.h>

#define BASE 10

int main(){
	int num, cifra;

	scanf("%d", &num);

	while(num > 0){
		cifra = num % BASE;
		num = num / BASE;

		printf("%d",cifra);
	}

	printf("\n");

	return 0;
}