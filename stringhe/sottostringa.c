#include <stdio.h>
#include <string.h>

#define DIM 30

int main(){

	char sottoseq[DIM + 1], stringa[DIM + 1];
	int i, conta_sottoseq, k, dim_sottoseq ,possibile_sottoseq;

	scanf("%s%s", sottoseq, stringa);

	dim_sottoseq = strlen(sottoseq);

	for(i = 0, conta_sottoseq = 0; stringa[i] != '\0'; i++){
		
		if(stringa[i] == sottoseq[0]){

			for(k = 1, possibile_sottoseq = 1; k < dim_sottoseq && possibile_sottoseq; k++){
		
				if(sottoseq[k] != stringa[i + k]){

					possibile_sottoseq = 0;
				}

			}

			if(possibile_sottoseq){
				conta_sottoseq++;
			}

		}

	}

	printf("%d e' il numero di sottosequenze '%s' in '%s'\n", conta_sottoseq, sottoseq, stringa);

	return 0;
}