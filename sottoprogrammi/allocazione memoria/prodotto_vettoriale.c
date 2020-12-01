#include <stdio.h>
#include <stdlib.h>

#define FILENAME "serie.txt"

float** mallocMatrice(int dim);
void freeMatrice(float **m, int dim);

int main(){

	FILE *fp;
	float **m;
	float *v;
	float pVett;
	int n, i, j;

	fp = fopen(FILENAME, "r");

	if(fp){
		printf("sono qua");
		fscanf(fp, "%d", &n);

		v = malloc(sizeof(float)*n);
		
		if(v){

			m = mallocMatrice(n);

			if(m){

				for(i = 0; i < n; i++){
					fscanf(fp, "%f", (v+i));
				}


				/*non si capisce la richiesta del testo*/
				for(i = 0, pVett = 0; i < n; i++){
					pVett += *(v + i) * *(v + i);
				}

				for(i = 0; i < n; i++){
					for(j = 0; j < n; j++){
						m[i][j] = v[i]*v[j];
					}
				}
				for(i = 0; i < n; i++){
					for(j = 0; j < n; j++)
						printf("%f  ", m[i][j]);
					printf("\n");
				}

				free(v);
			}
		}else{
			printf("Errore di allocazione\n");
		}

		fclose(fp);
	}else{
		printf("Errore di apertura del file\n");
	}

	return 0;
}

float** mallocMatrice(int dim){
	float **m;
	int i, errore;
	
	m = malloc(sizeof(float *) * dim);

	if(m){
		for(i = 0, errore = 0; i < dim && !errore; i++){
			m[i] = malloc(sizeof(float) * dim);
			if(!m[i])
				errore = 1;
		}
		if(errore){
			printf("Errore!\n");
			i--;
			for(; i >= 0; i--){
				free(m[i]);
			}
			free(m);
		}
	}else{
		printf("Errore nell'allocazione\n");
	}

	return m;
}