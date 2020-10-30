#include <stdio.h>

#define DIM 20

void acquisisci(int [], int);
void rimuovi_dup(int [], int *);
void intersezione(int [], int, int [], int, int [], int *);
void visualizza(int [], int );

int main(){

	int v1[DIM], v2[DIM], v3[DIM], i1[DIM], i2[DIM];
	int d1, d2, d3, di1, di2;

	d1 = DIM;
	d2 = DIM;
	d3 = DIM;

	acquisisci(v1, d1);
	acquisisci(v2, d2);
	acquisisci(v3, d3);

	rimuovi_dup(v1, &d1);
	rimuovi_dup(v2, &d2);
	rimuovi_dup(v3, &d3);

	intersezione(v1, d1, v2, d2, i1, &di1);
	intersezione(i1, di1, v3, d3, i2, &di2);

	visualizza(i2, di2);
	return 0;
}

void acquisisci(int a[], int dim){

	int i;
	for(i = 0; i < dim; i++){
		scanf("%d", &a[i]);
	}
}

void rimuovi_dup(int a[], int *dim){

	int i, j, found, newd;
	int *a2, *pj;

	/*quindi posso anche usare un puntatore, che ovviamente parte dalla base dell'array*/

	for(i = 0, a2 = a, newd = 0; i < *dim; i++){
		for(pj = a, found = 0; pj < a[i]; && !found; pj++){
			if(a[i] == *pj){
				found = 1;
			}

		}
		/*
			for(j = 0, found = 0; j < i; && !found; j++){
				if(a[i] == a[j]){
					found = 1;
				}	
		}
		*/

		if(!found){
			*a2 = a[i];
			a2++;
			newd++;
		}
	}

	*dim = a2 - a;

}

void intersezione(int a[], int da, int b[], int db, int c[], int *dc){
	int i, j, found;

	*dc = 0;

	for(i = 0; i < da; i++){
		for(j = 0, found = 0; j < db && !found; j++){
			if(a[i] == b[j]){
				found == 1;
			}
		}

		if(found){
			c[*dc] = a[i];
			(*dc)++;
		}
	}
}

void visualizza(int a[], int dim){
	int i;

	for(i = 0; i < dim; i++)
		printf("%d\n", a[i]);
}