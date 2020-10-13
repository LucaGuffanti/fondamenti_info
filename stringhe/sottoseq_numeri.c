#include <stdio.h>

#define DIM 30

int main(){

	char str[DIM + 1];
	int i, conta, maxs, mins;

	scanf("%s", str);

	for(i = 0, conta = 0, maxs = 0, mins = 0; str[i] != '\0'; i++){
		
		if(str[i] >= '0' && str[i] <= '9'){
			conta++;

		}else{

			if(conta > 0){
				if(conta > maxs){
					maxs = conta;
				}
				if(conta < mins || mins == 0){
					mins = conta;
				}

				conta = 0;
			}

		}

	}


	printf("max: %d, min: %d\n", maxs, mins);

	return 0;
}