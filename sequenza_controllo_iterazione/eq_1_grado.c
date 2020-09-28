#include <stdio.h>

int main(){

	float a, b, res;
	scanf("%f%f", &a, &b);
	if(a == 0 && b == 0){
		printf("Indeterminata\n");
	}
	else if (a == 0 && b != 0){
		printf("Impossibile\n");
	}else{
		res = (-b/a);
		printf("%f\n", res);
	}

	return 0;
}