#include <stdio.h>

#define DIM 20

int main(){

	int seq[DIM], seq2[DIM];
	int i, j, size2, flag;

	for(i = 0; i < DIM; i++){
		scanf("%d", &seq[i]);
	}

	
	for(i = 0, size2 = 0; i < DIM; i++){
		
		for(j = 0, flag = 0; j <size2 && !flag; j++){
			if(seq2[j] == seq[i])
				flag = 1;

		}

		if(!flag){
			seq2[size2] = seq[i];
			size2++;
		}

	}


	for(i = 0; i < size2; i++){
		printf("%d", seq2[i]);
	}


	printf("\nNumero di elementi unici: %d\n", size2);
	return 0;
}