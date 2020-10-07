#include <stdio.h>

#define DIM 10

int main(){

	int num[DIM], i;

	for(i = 0; i < DIM; i++){
		scanf("%d", &num[i]);
	}

	for(i = 0; i < DIM; i++){
		if(num[i]%2 == 0)
			printf("%d\n", num[i]);
	}

	for(i = 0; i < DIM; i++){
		if(num[i]%2 != 0)
			printf("%d\n", num[i]);
	}

	return 0;
}