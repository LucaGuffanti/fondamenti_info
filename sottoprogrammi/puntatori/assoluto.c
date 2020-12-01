#include <stdio.h>

#define MAXD 10

/*quando passo un'array PASSO ANCHE LA DIMENSIONE, SEMPRE*/
void array_ass(int *a, int dim);
/*
volendo esiste void array_ass(int a[], int dim); volendo possiamo omettere i nomi
mantentendo le quadre.
in questo modo indico che sto passando un array.
ovviamente poi nella funzione posso operare con la notazione degli array.
*/


int main(){

	int v[MAXD], i;

	for(i = 0; i < MAXD; i++){
		scanf("%d", /*(v+i)*/v[i]);
	}

	array_ass(v, MAXD);
	/*
	con array_ass(v + MAXD/2, MAXD/2); opero sulla seconda metà del codice
	*/

	for(i = 0; i < MAXD; i++)
		printf("%d\n", v[i]);

	return 0;

}


/*questa funzionerà per array di qualsiasi dimensione, poiché dim è un parametro*/
void array_ass(int *a, int dim){
	int i;
	for(i = 0; i < dim; i++){
		if(*(a + i) < 0)
			*(a + i) = -(*(a + i));
	}
}