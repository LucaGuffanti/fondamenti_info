#include <stdio.h>
#include <stdlib.h>

int** mallocMatrice(int );
void freeMatrice(int **, int);

int main(){

	int **m1, **m2;
	int n1, n2, i, j, somma, found;

	scanf("%d", &n1);
	m1 = mallocMatrice(n1);

	if(m1){
		for(i = 0; i < n1; i++){
			for(j = 0; j < n1; j++){
				scanf("%d", (*(m1+i)+j)); /*sto identificando la singola cella*/
			}
		}
		/*LEGGERE BENE: sottomatrici a somma nulla che partono da 0,0*/
		for(n2 = n1, found = 0; n2 > 0 && !found; n2--){
			for(i = 0, somma = 0; i < n2; i++){
				for(j = 0; j < n2; j++){
					somma += *(*(m1+i) + j);
				}
				if(somma == 0){
					found = 1;
					m2 = malloc(n2);

					if(m2){
						for(i = 0; i < n2; i++){
							for(j = 0; j < n2; j++){
								*(*(m2+i)+j) = *(*(m1+i)+j); /*m2[i][j] = m1[i][j]*/
							}
						}
					}
				}
			}
		}

		n2++;
		if(found && m2){
			for(i = 0; i < n2; i++){
				for(j = 0; j < n2; j++){
					printf("%d", *(*(m2+i) + j));
				}
				printf("\n");
			}
		}
		else if(!found){
			printf("Non ci sono sottomatrici a somma nulla\n");
			freeMatrice(m2, n2);

		}
		else{
			printf("m2 non allocata\n");
		}

		freeMatrice(m1, n1);

	}else{
		printf("m1 non allocata\n");
	}
	return 0;
}

int** mallocMatrice(int n){

	int **m; /*doppio puntatore per allocare la matrice*/
	int i, error;

	error = 0;

	m = malloc(sizeof(int*) * n); /*puntatore ad array di puntatori*/

	if(m){
		for(i = 0; i < n && !error; i++){
			*(m+i) = malloc(sizeof(int) * n); /*m[i]*/

			if(!*(m+i)){
				error = 0;
			}
		}

		if(error){
			printf("Errore malloc\n");
			for(i--; i >= 0; i--){
				free(m[i]);
			}
			free(m);
		}
	}else{
		printf("Errore malloc\n");
	}

	return m;
}

void freeMatrice(int **m, int n){
	int i;

	for(i = 0; i < n; i++){
		free(m[i]);
	}
	free(m);
}