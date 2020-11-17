#include <stdio.h>

int v_assoluto(int n);

int minore(int num1, int num2);


int main(){

	int a, b, min;

	scanf("%d%d", &a, &b);

	a = v_assoluto(a);
	b = v_assoluto(b);

	min =  minore(a, b);

	printf("%d\n", min);

	return 0;
}

int v_assoluto(int n){

	if (n < 0){
		n = -n;
	}

	return n;
}

int minore(int num1, int num2){

	int ris;

	if(num1 < num2){
		ris = num1;
	}else{
		ris = num2;
	}

	return ris;
}