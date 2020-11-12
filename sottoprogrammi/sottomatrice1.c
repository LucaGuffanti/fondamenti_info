#include <stdio.h>

#define NC_M 5
#define NC_SM 2

int conta_submatr(int [][NC_M], int, int [][NC_SM], int);

int main(){
	/*
	....
	*/
	return 0;
}

int conta_submatr(int m[][NC_M], int nr_m, int sm[][NC_SM], int nr_sm){
	int i, j, k, h, isSub, conta;

	for(i = 0, conto = 0; i <= nr_m - nr_sm; i++){

		for(j  = 0; j <= NC_M - NC_SM; j++){

			for(k = 0, isSub = 1; k < nr_sm && isSub; k++){

				for(h = 0, isSub = 1; h < NC_SM && isSub; h++){

					if(m[i + k][j + h] != sm[k][h]){
						isSub = 0;
					}
				}
			}
			if(isSub)
				conta++;
		}
	}

	return conta;
}
