#include <stdio.h>

#define PI 3.14

void cerchio(float, float *, float *);


int main(){

	float raggio, area, perimetro;
	int continua;

	do{
		scanf("%f", &raggio);

		cerchio(raggio, &area, &perimetro);

		printf("%f, %f\n", area, perimetro);

		scanf("%d", &continua);

	}while(continua != 0);

	return 0;
}

void cerchio(float r, float *a, float *p){

	*a = r * r * PI;
	*p = 2 * r * PI;
}