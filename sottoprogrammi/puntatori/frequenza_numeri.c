#include <stdio.h>

#define BASE 10

void analizzacifre(int, int*, int*);


int main(){

	int num, c, v;

	scanf("%d", &num);

	analizzacifre(num, &c, &v);

	printf("%d, %d volte\n", c, v);

	return 0;
}

void analizzacifre(int n, int *cifra, int *volte){

	int cifre[BASE], i;

	for(i = 0; i < BASE; i++){
		cifre[i] = 0;
	}


	while(n > 0){
		
		cifre[n%BASE]++;
		n = n/BASE;
	}

	*cifra = 0;
	*volte = 0;

	for(i = 0; i < BASE; i++){
		if(cifre[i] > *volte){
			*cifra = i;
			*volte = cifre[i];
		}
	}
}