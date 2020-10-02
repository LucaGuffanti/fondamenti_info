#include <stdio.h>

int main(){

	int a, succ;
	scanf("%d",&a);

	if(a != 0){
		scanf("%d", &succ);

		while(succ != 0){

			/*Eseguo il controllo richiesto*/
			if (2*a == succ){
				printf("%5d%5d\n", a, succ);
			}

			/*Aggiorno i valori delle variabili*/
			a = succ;
			scanf("%d", &succ);
		}
	}else{
		printf("Sequenza nulla.\n");
	}


	return 0;
}