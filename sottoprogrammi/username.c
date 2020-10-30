#include <stdio.h>

int check_username(char [], int, int, char[]);

int main(){

	/*
	...
	...
	*/

	return 0;
}

int check_username(char u[], int n, int nl, char symb[]){
	int i, conto_nl, j, no_symb;

	for(i = 0, conto_nl = 0, no_symb = 1; u[i] != '\0' && no_symb; i++, conto_n++){
		if((u[i] >= 'a' && u[i] <= 'z') || (u[i] >= 'A' && u[i] <= 'Z')){
			conto_nl++;
		}

		for(j = 0; symb[j] != '\0' && no_symb; j++){
			if(u[i] == symb[j]){
				no_symb = 0;
			}
		}
	}

	return (no_symb && conto_nl >= nl && i >= n);

}