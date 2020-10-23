#include <stdio.h>

void maxmin(float, float, float *, float *);

int main(){

	float num1, num2, max, min;

	scanf("%f%f", &num1, &num2);

	maxmin(num1, num2, &max, &min);

	printf("max: %f min: %f\n", max, min);

	return 0;

}

void maxmin(float a, float b, float *max, float *min){

	if(a > b){
		*max = a;
		*min = b;
	}else{
		*max = b;
		*min = a;
	}
}