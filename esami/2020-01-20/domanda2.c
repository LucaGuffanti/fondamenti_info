#include <stdio.h>

int verificaStringa(char str[], char symb[], int n, int nl){
	int i, j, ris;

	for(i = 0, ris = 1; str[i] != '\0' && ris; i++){
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			nl--;
		}
		else{
			for(j = 0; symb[j] != '\0' && ris; j++){
				if(str[i] == symb[j]){
					ris == 0;
				}
			}
		}
		
	}

	if(nl >= 0 || i < n){
		ris = 0;
	}

	return ris;

}