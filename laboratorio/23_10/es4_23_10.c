/*es4 del laboratorio del 23/10*/

#include <stdio.h>

#define DIM 5

int main(){

	int num[DIM], i, j, contazero, totzero;

	for(i = 0; i < DIM; i++){
		scanf("%d", &num[i]);
	}

	for(i = 0; i < DIM; i++){
		printf("%d ",num[i]);
	}

	printf("\n");

	for(i = 0, totzero = 0; !totzero; i++){
		
		contazero = 0;
				
		for(j = 0; j < DIM; j++){
			
			if(num[j] > 0){
				printf("* ");
				num[j]--;
			}else{
				printf("  ");
				contazero++;
			}

			totzero = contazero == DIM;
		}

		printf("\n");
	}

	return 0;
}