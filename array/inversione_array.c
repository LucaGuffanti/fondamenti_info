#include <stdio.h>

#define DIM 5

int main(){

	int num[DIM], i, j, swap;

	for(i = 0; i < DIM; i = i + 1){
		scanf("%d", &num[i]);
	}

	for(i = 0, j = DIM - 1; i < DIM/2; i++, j--){
		swap = num[i];
		num[i] = num[j];
		num[j] = swap;
	}

	for(i = 0; i < DIM; i++){
		printf("%d\n", num[i]);
	}


	return 0;
}