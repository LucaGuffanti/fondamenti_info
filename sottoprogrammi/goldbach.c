#include <stdio.h>

int isPrime(int n);


int main(){

	int n, i, j, termina;

	scanf("%d", &n);

	while(n < 2 || n % 2 != 0){
		printf("Inserire un numero pari maggiore o uguale a 2\n");
		scanf("%d", &n);
	}

	for(i = 1, j = 0, termina = 1; i + j <= n && termina; i++){
		
		for(j = 1; i + j <= n; j++){
			
			if(isPrime(i) && isPrime(j) && i + j == n){
				printf(" %3d %3d sono due numeri primi che sommati danno %3d\n", i, j, n);

			}
		}

		j = i + 1;
	}

	return 0;
}

int isPrime(int n){

	int prime, i;

	for(i = 2, prime = 1; i * i <= n && prime; i++){
		if(n % i == 0){
			prime = 0;
		}
	}

	return prime;

}