#include <stdio.h>

int isPrime(int n);


int main(){

	int n, i;

	scanf("%d", &n);

	while(n < 2 || n % 2 != 0){
		printf("Inserire un numero pari maggiore o uguale a 2\n");
		scanf("%d", &n);
	}
		
	for(i = 1; i <= n/2; i++){
			
		if(isPrime(i) && isPrime(n-i)){
			printf(" %3d %3d sono due numeri primi che sommati danno %3d\n", i, n-i, n);

		}

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