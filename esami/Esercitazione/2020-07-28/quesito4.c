#include <stdio.h>

#define NCOLS 10

void centra(int [][NCOLS], int[][NCOLS], int, int);

void centra(int m[][NCOLS], float c[][NCOLS], int rig){
	int i, j;
	float somma, media;

	for(j = 0; j < NCOLS; j++){
		for(i = 0, somma = 0, media = 0; i < rig; i++){
			somma += m[i][j];
		}
		media = somma/rig;
		for(i = 0; i < rig; i++){
			c[i][j] = m[i][j] - media;
		}
	}
}