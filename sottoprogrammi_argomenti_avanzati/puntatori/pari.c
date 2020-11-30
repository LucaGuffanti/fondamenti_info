#include <stdio.h>

#define MAXDIM 10

void array_pari(int [], int [], int, int *);

int main(){

	int v1[MAXDIM], v2[MAXDIM], d1, d2;
	int i;

	for(i = 0; i < MAXDIM; i++){
		scanf("%d", &v1[i]);
	}

	array_pari(v1, v2, MAXDIM, &d2);

	for(i = 0; i < d2; i++){
		printf("%d\n", v2[i]);
	}

	printf("numero di pari: %d\n", d2);

	return 0;
}

void array_pari(int a1[], int a2[], int d1, int *d2){
	
	int i;
	
	for(i = 0, *d2 = 0; i < d1; i++){
		
		if(a1[i]%2 == 0){
			a2[*d2] = a1[i];
			(*d2)++; 
		}
	}

}