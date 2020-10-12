#include <stdio.h>

#define DIM 50

int main(){

	char s1[DIM + 1], s2[DIM + 1];
	int i, j;


	scanf("%s", s1);

	/*
		gli indici degli array qui scorrono con due velocità diverse:
		i - si riferisce alla stringa s1, e continua a muoversi fino al suo termine
		j - si riferisce alla stringa s2, si muove se e solo se l'elemento i-esimo di s1
			non è una vocale, per permettere la corretta copiatura del carattere in s2
	*/

	for(i = 0, j = 0; s1[i] != '\0'; i++){
		if(s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'u'){
			s2[j] = s1[i];
			j++;
		}

		
	}

	s2[j] = '\0';

	printf("%s\n", s2);

	return 0;
}