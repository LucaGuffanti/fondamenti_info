#include <stdio.h>

#define DIM 50

int main(){

	char s1[DIM + 1], s2[DIM + 1];
	int i;

	scanf("%s", s1);

	for(i = 0; s1[i] != '\0'; i++){
		switch(s1[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				s2[i] = '*';
				break;
			default:
				s2[i] = s1[i];
		}
	}

	printf("%s\n", s2);

	return 0;
}