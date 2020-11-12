#include <stdio.h>

float potenza(int, int);


int main(){

	int m,n;

	scanf("%d%d", &m, &n);

	printf("%f\n", potenza(m, n));

	return 0;
}

float potenza(int a, int b){
	if(b == 0)
		return 1;
	if(b > 0)
		return a * potenza(a, b-1);
	if(b < 0)
		return (1.0/a) * potenza(a, b + 1);
}