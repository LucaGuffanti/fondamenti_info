#include <stdio.h>

#define BASE 2
#define DIM 10

int main(){

	int val, bit[DIM], i;

	scanf("%d", &val);

	while(val > 1023){
		printf("Inserire un numero minore di 1024.\n");
		scanf("%d", &val);
	}
/*	UNO DEI DUE MODI E' EQUIVALENTE
	i = 0;
	while(i < DIM){
		if(val > 0){
			bit[i] = val % BASE;
			val = val/BASE;
		}else{
			bit[i] = 0;
		}
		i++;
	}

	for(i = DIM - 1; i >= 0; i--){
		printf("%d", bit[i]);
	}
	printf("\n");

*/
	i = DIM - 1;
	while(i >= 0){
		if(val > 0){
			bit[i] = val % BASE;
			val = val/BASE;
		}else{
			bit[i] = 0;
		}
		i--;
	}

	for(i = 0; i < DIM; i++){
		printf("%d", bit[i]);
	}
	printf("\n");

	return 0;
}