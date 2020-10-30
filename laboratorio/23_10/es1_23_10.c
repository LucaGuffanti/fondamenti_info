/*es1 del laboratorio del 23/10*/

#include <stdio.h>

#define DIM 20

int main(){

	int a1[DIM], a2[DIM];
	int i, j;

	for(i = 0; i < DIM; i++){
		scanf("%d", &a1[i]);
	}

	for(i = 0, j = 0; i < DIM; i++){
		
		if(a1[i]%2 == 0){
			a2[j] = a1[i];
			j++;
		
		}
	}

	for(i = 0; i < DIM; i++){

		if(a1[i]%2 != 0){
			a2[j] = a1[i];
			j++;
		
		}
	}


	for(i = 0; i < DIM; i++){
		printf("%d\n", a2[i]);
	}

	return 0;
}