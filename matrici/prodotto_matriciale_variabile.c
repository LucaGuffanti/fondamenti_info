/*
Due matrici a e b sono moltiplicabili se
a = righe_1xcolonne_1 e b=righe_2xcolonne_2,
hanno colonne_1 == righe_2.
m, cioè il prodotto sarà pari a una matrice righe_1xcolonne_2
*/

#include <stdio.h>

#define DIM_MAX 6

int main(){
/*Esempio di sottoutilizzo dell'array sovradimensionato*/
	
	int rig_a, col_a, rig_b, col_b, rig_m, col_m;
	int a[DIM_MAX][DIM_MAX], b[DIM_MAX][DIM_MAX], m[DIM_MAX][DIM_MAX];
	int i, j, k;

	/**/
	do{
		scanf("%d%d", &rig_a, &col_a)
	}while(rig_a <= 0 || rig_a > DIM_MAX || col_a <= 0 || col_a > DIM_MAX);

	do{
		scanf("%d%d", &rig_b, &col_b)
	}while(rig_b <= 0 || rig_b > DIM_MAX || col_b <= 0 || col_b > DIM_MAX);

	
	for(i = 0; i < rig_a; i++){
		for(j = 0; j < col_a; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(i = 0; i < rig_b; i++){
		for(j = 0; j < col_b; j++){
			scanf("%d", &b[i][j]);			
		}
	}


	if(col_a == rig_b){
		rig_m = rig_a;
		col_m = col_b;

		for(i = 0; i < rig_m; i++){
			for(j = 0; j < col_m; j++){
				for(k = 0, m[i][j] = 0; k < col_a; k++){
					m[i][j] = m[i][j] + (a[i][k] * b[k][j]);
				}
			}
		}
	}else{
		printf("Prodotto non calcolabile.\n")

	}


	return 0;
}