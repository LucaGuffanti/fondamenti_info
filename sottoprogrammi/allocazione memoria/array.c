#include <stdio.h>
#include <stdlib.h>

#define N 10

int* arraycopy(int [], int);

int main(){

	int v[N];
	int *v2;
	int i;

	for(i = 0; i < N; i++){
		scanf("%d", &v[i]);
	}

	v2 = arraycopy(v1, N);
	if(v2){
		
		for(i = 0; i < N; i++){
			printf("%s\n", v2[i]);
		}

		free(v2);
	}else{
		printf("Errore\n");
	}

	return 0;
}

int *arraycopy(int a1[], int dim){
	
	/*copio un array in un altro*/

	int *a2;
	int i;

	a2 = malloc(sizeof(int) * dim);

	if(a2){
		for(i = 0; i < dim; i++){
			scanf("%d", a2+i);
		}

	/*se avviene un errore, semplicemente mi ritorna null*/
	/*quindi noi qui ci limitiamo a restituire null in caso di errore3*/
	return a2;
}