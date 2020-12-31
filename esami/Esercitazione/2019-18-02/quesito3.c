#include <stdio.h>

#define NCOL 3

void identificaElemento(int [][NCOL], int, int, int*, int*);

int main(){
	int m[NCOL][NCOL];
	int i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < NCOL; j++){
			scanf("%d", &m[i][j]);
		}
	}

	identificaElemento(m, 11, 2, &i, &j);
	printf("%d,%d\n",i, j);

	return 0;
}

void identificaElemento(int m[][NCOL], int val, int n_righe, int *row, int *cols){
	int somma, found, i, j;
	for(i = 0, found = 0; i < n_righe && !found; (i)++){
		somma = 0;
		for(j = 0; j < NCOL && !found; (j)++){
			somma += m[i][j];
			if(somma > val){
				found = 1;
				*row = i;
				*cols = j;
			}
		}
	}
	if(!found){
		*row = *cols = -1;
	}	
}