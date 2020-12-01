#include <stdio.h>

#define NC 5
#define NR 5
/*

void stampa(int (*)[NC], int ); bisogna necessariamente conoscere la dimensione dell'array*/

/*con la dimensione predefinita, noi diamo al compilatore i valori per la linearizzazione*/

/*vale anche questo*/
void stampa(int [][], int);

int main(){

	int m[NR][NC];
	int (*p)[NC]; /*p è un puntatore ad array di 5 int, quindi punta alle righe*/
	int *p1[5]; /*p1 sarà un array di 5 puntatori ad int*/
	

	p = m;
	/*accedo alla riga 0, nell'indice 1*/

	(*p)[1] = 0;

	/*scrivo all'elemento della riga 1*/

	(*(p + 1))[1] = 5; /*mi sposto di 1 array più avanti*/
	/*deferenziando p trovo un puntatore di tipo diverso, in questo caso un puntatore a int
	che mi genera l'array*/
	/*i * N_COL + j*/ 
	/*effettivamente qui entro nella casella 6*/ 

	m[2][3] = 7; /*2 * 5 + 3 = 13*/

	/*p = m1 /*così impazzisce la linearizzazione*/

	/*(*(p+1))[1] = 3; /*accederò all'elemento 6 della prima riga, NO*/


	/*popolo m*/;

	stampa(m, NR);

	return 0;
}


void stampa(int m[][NC], int nr){
	int i, j;
	for(i = 0; i < nr; i++){
		for(j = 0; j < NC; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}