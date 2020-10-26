#include <stdio.h>

int sqrt_intera(int, int *);

int main(){

	int num, ris, esatto;

	scanf("%d", &num);

	esatto = sqrt_intera(num, &ris);

	printf("%d %d\n", ris, esatto);

	return 0;
}

int sqrt_intera(int n, int *r){
	int i = 1;
	*r = 1;
	int prec;
	while(i * i <= n){
		*r = i;
		i++;
	}

	return(*r) * (*r) == n;

}