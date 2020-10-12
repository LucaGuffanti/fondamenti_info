#include <stdio.h>
#include <string.h>


#define SDIM 30

int main(){

	char s1[SDIM + 1], s2[SDIM + 1], sconc[2 * SDIM + 1];
	int i, j;

	scanf("%s%s", s1, s2);

	for(i = 0; s1[i] != '\0'; i++){
		sconc[i] = s1[i];
	}

	for(j = 0; s2[j] != '\0'; j++){
		sconc[i + j] = s2[j];
	}

	sconc[i + j] = '\0';

	printf("%s\n", sconc);

	return 0;
}