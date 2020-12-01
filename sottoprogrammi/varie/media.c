#include <stdio.h>

float media(int num1, int num2);

int main(){

	int a, b;
	float m;

	scanf("%d%d", &a, &b);

	m = media(a, b);

	printf("La media di %d e %d e': %f\n",a, b, m);

	scanf("%d%d", &a, &b);

	m = media(a, b);

	printf("La media di %d e %d e': %f\n",a, b, m);	

	return 0;
}

float media(int num1, int num2){

	float ris = (float)(num1 + num2)/2.0;

	return ris;
}
