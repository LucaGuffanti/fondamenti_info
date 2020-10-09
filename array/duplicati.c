#include <stdio.h>

#define DIM 10

int main(){
	int seq[DIM], num, i, j;
	int duplicati;

	for (i = 0; i < DIM; i++){
		scanf("%d", &seq[i]);
	}


	for(i = 0, duplicati = 0; i < DIM && !duplicati; i++){
		
		for(j = 0, j < i && !duplicati; j++){

			if(seq[i] == seq[j] /*&& i != j*/){
				flag = 1;
			}
		}
	}

	printf("%d\n", flag);
	return 0;
}