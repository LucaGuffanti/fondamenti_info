#include <stdio.h>
#define MAXDIM 10


int somma(int [], int );

int main(){

	int v[MAXDIM], s1, s2, i;

	for(i = 0; i < MAXDIM; i++){
		scanf("%d", &v[i]);
	}

	s1 = somma(v, MAXDIM/2);

	s2 = somma(v + MAXDIM/2, MAXDIM/2);

	if(s1 > s2){
		printf("%d > %d\n", s1, s2);
	}else{
		printf("%d > %d\n", s2, s1);
	}

	return 0;
}


int somma(int a[], int dim){
	int s, i;

	for(s = 0, i = 0; i < dim; i++)
		s = s + a[i];

	return s;
}
