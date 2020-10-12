#include <stdio.h>

#define DIM 30

int main(){

	char s1[DIM + 1], s2[DIM + 1];
	int i;

	scanf("%[^\n]", s1);

	for(i = 0; s1[i] != '\0'; i++){
		if(s1[i] >= 'a' && s1[i] <= 'z')
			s2[i] = s1[i] - 'a' + 'A';
		else
			s2[i] = s1[i];
	}

	s2[i] = '\0';

	printf("%s\n", s2);

	return 0;
}