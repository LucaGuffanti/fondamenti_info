#include <stdio.h>
#include <stdlib.h>

#define N 10


void copiaPari(int [], int, int **, int *);
/*int ** è un puntatore ad una cella di tipo puntatore a int*/

int main(){

	int v[N];
	int *pari;
	int dimpari, i;

	for(i = 0; i < N; i++){
		scanf("%d", &v[i]);
	}

	copiaPari(v, N, &pari, &dimpari);

	if(dimpari != -1 && pari){	
		
		for(i = 0; i < dimpari; i++){
			printf("%d\n", pari[i]);
		}

		free(pari);

		/*ora manca liberare la memoria*/

	}else{
		printf("Errore\n");
	}

	return 0;
}

void copiaPari(int a[], int adim, int **b, int *bdim){
	/*qui restituisco il mio array passato per indirizzo ma allocato alla memoria*/
	int i, j;

	for(i = 0, *bdim = 0; i < adim; i++){
		if(a[i]%2 == 0)
			(*bdim)++;
	}
	/*assegnamo la malloc alla cella puntata da b*/
	*b = malloc(sizeof(int) * (*bdim)); 

	if(*b){
		for(i = 0, j = 0; i < adim; i++){
			if(a[i]%2 == 0){
				*((*b) + j) = a[i]; /*vale anche (*b)[j]*/
				j++;
			}
		}
	}
	else{
		*bdim = -1;
	}

}