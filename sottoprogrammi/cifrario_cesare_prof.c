#include <stdio.h>
#include <string.h>

#define PASSO 3
#define STRDIM 20

char cifra(char);
char decifra(char);
int verificalettera(char);


int main(){

	char m1[STRDIM + 1], m2[STRDIM + 1], m3[STRDIM + 1];
	int i;

	scanf("%s", m1);

	for(i = 0; m1[i] != '\0'; i++){
		if(verificalettera(m1[i]))
			m2[i] = cifra(m1[i]);
		else
			m2[i] = m1[i];
	}

	m2[i] = '\0';
	printf("cifrato: %s\n", m2);

	for(i = 0; m2[i] != '\0'; i++){
		if(verificalettera(m2[i]))
			m3[i] = decifra(m2[i]);
		else
			m3[i] = m2[i];
	}

	m3[i] = '\0';

	printf("decifrato: %s\n", m3);

	printf("%d\n", strcmp(m1, m3));

	return 0;
}

char cifra(char chiaro){
	char cifrato;

	if(chiaro <= 'z' - PASSO)
		cifrato = chiaro + PASSO;
	else
		cifrato = chiaro + PASSO - ('z' - 'a' + 1);

	return cifrato;
}

char decifra(char cifrato){
	char chiaro;

	if(cifrato >= 'a' + PASSO)
		chiaro = cifrato - PASSO;
	else
		chiaro = cifrato - PASSO +('z' - 'a' + 1);

	return chiaro;
}

int verificalettera(char c){
	return c >= 'a' && c <= 'z';
}