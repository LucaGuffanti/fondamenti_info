#include <stdio.h>

#define DIM 10

int main(){

	char s1[DIM + 1], s_voc[DIM + 1];
	int i, contavoc;

	scanf("%s", s1);

	for(i = 0, contavoc = 0; s1[i] != '\0'; i++){

		if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u'){
			printf("Vocale %c nell'indice %d\n", s1[i], i);
			s_voc[contavoc] = s1[i];
			contavoc++;

		}
	}

	s_voc[contavoc] = '\0';

	printf("%s\n", s_voc);

}