#include <stdio.h>

#define N 10

int analizza(int [], int, int, int);

int main(int argc, char* argv[]){
	int v[N];
	int i;
	int m;

	for(i = 0; i < N; i++){
		scanf("%d", &v[i]);
	}
	scanf("%d", &m);

	printf("%d\n", analizza(v, N, 0, m));

	return 0;

}

int analizza(int v[], int dimensione, int indice, int m){
	
	int result;

	if(indice == dimensione - 1){
		return v[indice] > m; 
	}else{
		result = analizza(v, dimensione, indice+1, m);

		if(v[indice] > m && result = 1){
			return 1;
		}else{
			return 0;
		}
	}
}