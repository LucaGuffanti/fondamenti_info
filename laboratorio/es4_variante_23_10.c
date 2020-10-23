/*variante dell'es4 del laboratorio del 23/10*/

#include <stdio.h>

#define DIM 5

int main(){

	int num[DIM], num2[DIM], i, j, maxindex, max;

	for(i = 0; i < DIM; i++){
		scanf("%d", &num[i]);
	}

	for(i = 0; i < DIM; i++){
		num2[i] = num[i];
	}

	for(i = 1, maxindex = 0; i < DIM; i++){
		
		if(num[i] > num[maxindex]){
			maxindex = i;

		}
	}

	max = num[maxindex];

	for(i = max; i > 0; i--){
		for(j = 0; j < DIM; j++){
			if(num2[j] == i){
				num2[j]--;
				printf("* ");
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}

	for(i = 0; i < DIM; i++){
		printf("%d ", num[i]);
	}

	printf("\n");


	return 0;
}