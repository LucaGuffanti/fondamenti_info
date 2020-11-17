#include <stdio.h>

#define MAXDIM 3

void acquisizione(int [], int);

void rimozione_duplicati(int [], int *);

void intersezione(int [], int [], int [], int, int, int *);

int main(){

	int v1[MAXDIM], v2[MAXDIM], vin[MAXDIM], vin2[MAXDIM], v3[MAXDIM];
	int dim1, dim2, dim3, dimin, dimin2, i;

	dim1 = MAXDIM; 
	dim2 = MAXDIM;
	dim3 = MAXDIM;

	acquisizione(v1, dim1);
	acquisizione(v2, dim2);
	acquisizione(v3, dim3);

	intersezione(v1, v2, vin, dim1, dim2, &dimin), 

	intersezione(vin, v3, vin2, dimin, dim3, &dimin2);

	for(i = 0; i < dimin2; i++){
		printf("%d\n", vin2[i]);
	}



	return 0;
}

void acquisizione(int v[], int dim){
	
	int i;
	for(i = 0; i < dim; i++){
		scanf("%d", &v[i]);
	}

}

void rimozione_duplicati(int v[], int *dim){

	int temp[*dim];
	int numero, i, j, doppio, size;

	for(i = 0; i < *dim; i++){
		temp[i] = 0;
	}

	size = *dim;
	*dim = 0;

	for(i = 0, doppio = 0; i < size; i++){
		numero = v[i];
		for(j = 0, doppio = 0; j <= i && !doppio; j++){
			if(temp[j] == numero){
				doppio = 1;
			}
		}

		if(!doppio){
			temp[*dim] = numero;
			(*dim)++;
		}
	}

	for(i = 0; i < *dim; i++){
		v[i] = temp[i];
	}
}

void intersezione(int v1[], int v2[], int vi[], int d1, int d2, int *di){

	int i, j, trovato, numero;
	int somma[d1 + d2];

	for(i = 0; i < d1; i++){
		somma[i] = v1[i];
	}
	for(j = 0; j < d2; j++){
		somma[i + j] = v2[j];
	}

	*di = 0;

	for(i = 0, trovato = 0; i < d1 + d2; i++){
		numero = somma[i];
		for(j = i + 1, trovato = 0; j < d1 + d2 && !trovato; j++){
			if(numero == somma[j]){
				trovato = 1;
				vi[*di] = numero;
				(*di)++;
			}
		}
	}	

	rimozione_duplicati(v1, di);


	
}