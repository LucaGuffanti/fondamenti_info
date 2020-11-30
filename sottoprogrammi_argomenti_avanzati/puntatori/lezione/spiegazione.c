#include <stdio.h>

int assoluto(int);

void swap(int, int);

void swap2(int *, int *);

int main(){

	/*
	int n, ass;

	scanf("%d", &n);

	ass = assoluto(n);
	swap(num, ass);
	*/
	
	int num1, num2;

	scanf("%d%d", &num1, &num2); /*collego il record di attivazione della scanf con quello 
	del main. per questo sono necessarie le &.*/

	swap2(&num1, &num2); /*la funzione si aspetta due indirizzi*/

	printf("%d %d\n", num1, num2);
	return 0;
}

int assoluto(int n){
	if(n < 0)
		n = -n;

	return n;
}

/*QUESTA NON FUNZIONA*/
void swap(int a, int b){
	int temp;

	temp = a;
	a = b;
	b = temp;
}

/*QUESTA INVECE FUNZIONA*/
/*eseguo lo scambio sui contenuti delle celle puntate*/
void swap2(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}