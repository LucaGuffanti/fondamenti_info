#include <stdio.h>

#define DIM 5

int main(){

	int num[DIM], i;

	for(i = 0; i < DIM; i = i + 1){
		scanf("%d", &num[i]);
	}

	for(i = DIM - 1; i >= 0; i = i - 1){
		printf("%d ", num[i]);
	}

	printf("\n");

	return 0;
}