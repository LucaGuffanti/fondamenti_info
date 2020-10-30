#include <stdio.h>

#define MAXDIM 10

int main(){

	int m[MAXDIM][MAXDIM], s[MAXDIM][MAXDIM];
	int i, j, k, h, contenuta, conta, mdim, sdim;

	do{
		printf("Inserire le dimensioni:\n");
		scanf("%d%d", &mdim, &sdim);
	}while(sdim > mdim);


	printf("Inserire la matrice m:\n");
	for(i = 0; i < mdim; i++){
		for(j = 0; j < mdim; j++){
			scanf("%d", &m[i][j]);
		}
	}
	printf("Inserire la matrice s:\n");
	for(i = 0; i < sdim; i++){
		for(j = 0; j < sdim; j++){
			scanf("%d", &s[i][j]);
		}
	}

	conta = 0;

	for(i = 0; i < mdim; i++){
		
		for(j = 0; j < mdim; j++){
		
			if((j + sdim - 1 < mdim) || (i + sdim - 1 < mdim)){
		
				for(k = 0, contenuta = 1; k < sdim && contenuta; k++){
		
					for(h = 0; h < sdim && contenuta; h++){
		
						if(m[i + k][j + h] != s[k][h]){
		
							contenuta = 0;
						}
					}
				}

				if(contenuta){
					conta++;
				}
			}
		}
	}

	printf("%d\n", conta);





	return 0;
}