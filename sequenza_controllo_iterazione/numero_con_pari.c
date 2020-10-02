#include <stdio.h>


int main(){

	int num, cifre_pari;
	scanf("%d", &num);

	while(num > 0 && cifre_pari){
		/*Una cifra e' pari se il resto della divisione per 2 e' pari a 0*/
		cifre_pari = (num%2 == 0);
		num = num/10;
	}

	if(cifre_pari){
		printf("Il numero inserito e' composto da sole cifre pari.\n");
	}else{
		printf("Il numero inserito e' composto da una o piu' cifre dispari.\n");
	}

	return 0;
}