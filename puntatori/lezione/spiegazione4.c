//puntatori ed array


#include <stdio.h>

#define MAXS 50

int main(){

	char str[MAXS + 1];
	char *p;

	int l1, l2, l3; //calcolo in 3 modi diversi la lunghezza della stringa

	scanf("%s", str);

	p = str;

	//uso dell'aritmetica dei puntatori


	for(l1 = 0; str[l1] != '\0'; l1++);

	for(p = str, l2 = 0; *(p + l2) != '\0'; l2++);

	for(p = str; *p != '\0' ; p++);
	l3 = p - str;		

	printf("%d %d %d\n",l1, l2, l3 );

	return 0;
}