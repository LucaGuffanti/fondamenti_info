#include <stdio.h>

#define DIM 30

int main(){

	char s1[DIM + 1], s2[DIM + 1];
	int i, flag; //flag è una variabile logica che si riferisce all'appartenenza ai caratteri minuscoli o allo spazio

	scanf("%[^\n]", s1);

	for(i = 0, flag = 1; s1[i] != '\0' && flag; i++){
		flag = s1[i] == ' ' || (s1[i] >= 'a' && s1[i] <= 'z');
	}

	if(flag)
		printf("Composizione corretta.\n");
	else
		printf("Composizione scorretta.\n");
	



	return 0;
}