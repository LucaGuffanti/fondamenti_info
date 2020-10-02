#include <stdio.h>

#define BASE 10

int main(){
	int num1, temp, num1_inverso, palindromo;

	scanf("%d", &num1);

	/*Inverto num1 per poi eseguire un semplice confronto*/
	temp = num1;
	num1_inverso = 0;

	while(temp%10 > 0){
		num1_inverso = (num1_inverso)*10 + temp%10;
		temp = temp/10;	
	}

	palindromo = num1 == num1_inverso;

	printf("%d\n", palindromo);

	


	return 0;
}