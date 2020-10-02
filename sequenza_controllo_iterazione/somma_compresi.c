#include <stdio.h>

int main(){
	int a, b, i, temp, somma;
	scanf("%d%d", &a, &b);

	if(b < a){
		temp = b;
		b = a;
		a = temp;
	}

	somma = 0;
	i = a + 1;

	while(i < b){
		somma = somma + i;
		i = i + 1;
	}

	printf("Somma:%d\n", somma);
	return 0;
}