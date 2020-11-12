#include <stdio.h>
#define DIM 10


int max(int [], int );

int main(){
	int arr[DIM];
	int i;

	for(i = 0; i < DIM; i++){
		scanf("%d", (arr+i));
	}

	printf("%d\n", max(arr, DIM));

	return 0;
}


int max(int a[], int dim){
	int max_succ;

	if(dim == 1)
		return a[0];
	else
		max_succ = max(a + 1, dim - 1); /*vado avanti di una cella e restringo il campo d'indagine*/

	if(max_succ > *(a))
		return max_succ;
	else
		return a[0];
}
