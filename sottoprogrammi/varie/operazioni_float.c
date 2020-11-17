#include <stdio.h>

/*Questo è un prototipo*/
float maggiore(float num1, float num2);

int main(){

	float a, b, c, max;

	scanf("%f%f%f", &a, &b, &c);

	max = maggiore(a, b);

	printf("il maggiore tra %f, %f e' %f\n", a, b, max);

	max = maggiore(maggiore(a,b), c);

	printf("il maggiore tra %f, %f e %f e' %f\n", a, b, c, max);

	return 0;
}


float maggiore(float num1, float num2){

	float ris;

	if(num1 > num2)
		ris = num1;
	else 
		ris = num2;

	return ris;
}