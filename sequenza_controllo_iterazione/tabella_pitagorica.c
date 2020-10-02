#include <stdio.h>

#define DIM 10

int main(){
	int i, j, val;

	i = 1;
	while(i <= DIM){
		j = 1;
		while(j <= DIM){
			val = i * j;
			printf("%4d", val);
			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}



	return 0;
}