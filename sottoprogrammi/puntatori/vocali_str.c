#include <stdio.h>

#define DIM 30

int conta_vocali(char *);

int main(){

	char str[DIM + 1];
	int cont;

	scanf("%[^\n]", str);

	cont = conta_vocali(str);

	printf("n: %d\n", cont);

	return 0;
}

int conta_vocali(char *str){

	int cont;
	int i;

	for(i = 0, cont = 0; *(str + i) != '\0'; i++){
		
		if(*(str + i) == 'a' || *(str + i) == 'e' || *(str + i) == 'i' || *(str + i) == 'o' || *(str + i) == 'u'){
			cont++;
		}
	}

	return cont;
}