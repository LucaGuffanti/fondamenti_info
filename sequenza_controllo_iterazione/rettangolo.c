#include <stdio.h>

int main(){

	int a, b, i, j;
	scanf("%d%d", &a, &b);

	while(a <= 0 && b <= 0){
		printf("Entrambi i numeri devono essere positivi: inserirli nuovamente.\n");
		scanf("%d%d", &a, &b);
	}

	/*
	Per rappresentare il rettangolo uso due cicli while annidati, con due variabili
	come contatori, i e j, utili per "scorrere" righe e colonne. La struttura del rettangolo è tale 
	per cui si ha a come larghezza e b come altezza	
	*/

	i = 0;
	while(i < b){
		j = 0;
		if( i == 0 || i == b-1){
			while(j < a){
				printf("*");
				j = j + 1;
			}
			printf("\n");
		}else{

			while(j < a){
				if(j == 0 || j == a-1){
					printf("*");
				}else{
					printf(" ");
				}

				j = j + 1;
			}
			printf("\n");
		}
		i = i + 1;
	}


	

	return 0;
}