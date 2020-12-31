#include <stdio.h>

#define DIM 5

int verificaMatrice(int [][DIM], int);

int verificaMatrice(int m[][DIM], int d){
	int i;
	int j;
	int k;
	int visto[DIM];
	int col, rig;
	int num;

	col = rig = 0;
	for(i = 0; i < d; i++){
		visto[i] = 0;
	}

	/*verifichiamo le righw*/

	for(i = 0, rig = 1; i < d && rig; i++){
		for(j = 0; j < d && rig; j++){
			num = m[i][j] - 1;
			visto[num]++;
		}
		for(k = 0; k < d; k++){
			if(visto[k] != 1){
				rig = 0;
			}
		}
		for(k = 0; k < d; k++){
			visto[k] = 0;
		}
	}

	/*verifichiamo le colonne*/
	if(rig){
		for(j = 0, col = 1; j < d && col; j++){
			for(i = 0; i < d && col; i++){
				num = m[i][j] - 1;
				visto[num]++; 
			}
		}
		for(k = 0; k < d; k++){
			if(visto[k] != 1){
				col = 0;
			}
		}
		for(k = 0; k < d; k++){
			visto[k] = 0;
		}
	}

	return col && rig;
}