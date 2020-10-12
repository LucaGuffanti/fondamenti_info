#include <stdio.h>
#include <string.h>


#define SDIM 30

int main(){

	char s1[SDIM + 1], s2[SDIM + 1];
	int i, j;

	scanf("%s", s1);

	for(i = 0, j = strlen(s1); i < j; i++){
		s2[i] = s1[j - 1 - i];
	}

	s2[i] = '\0'; 	//METTERE SEMPRE IL CARATTERE TERMINATORE

	printf("%s\n", s2);

	return 0;
}