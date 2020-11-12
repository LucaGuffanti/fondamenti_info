#include <stdio.h>
#include <string.h>

#define NC 10

/*noi vogliamo "parametrizzare la funzione di stampa, non rimanendo legati
alla macro definita in precedenza*/

/*con un puntatore ad intero, gestisco in modo esplicito la linearizzazione*/
/*coxì lavoro con matrici di ogni dimensione*/
void stampa(int *, int, int);
void stampaSotto(int *, int, int, int, int);

int main(){
	int matr[NC][NC];

	/**/
	int matr2[4][4]; 



	stampa(&matr[0][0], NC, NC); /*devo quindi passare il primo elemento della matrice*/
	stampa(&matr2[0][0], 4, 4); /*se sottoutilizzata mi servono altri parametri per righe e colonne utilizzate*/
	return 0;
}

void stampa(int *m, int righe, int colonne){ 
	/*colonne è la costante che definisce il massimo numero di colonne della matrice, perché eseguo una linearizzazione esplicita*/

	int i, j;


	/*non potrò mettere m[i][j] perché m non è più un puntatore ad array*/
	/*perché ora m punta alla prima cella*/
	
	for(i = 0; i < righe; i++){
		for(j = 0; j < colonne; j++){
			printf("%d\n", *((m + i*colonne)+j)); /*questo è l'indirizzo che ci interessa. COLONNE QUI NELLA LINEARIZZAZIONE E' LA COSTANTE*/
		}


		/*((m + col*1)+1) = 10, così modifico l'elemento 1 della riga 1 */
		printf("\n");
	}
}

void stampaSotto(int *m, int righe, int colonne, int rusate, int cusate){
	int i, j;
	for(i = 0; i < rusate; i++){
		for(j = 0; j < cusate; j++){

			printf("%d", *((m + i*colonne) + j));

		}

		printf("\n");
	}
}