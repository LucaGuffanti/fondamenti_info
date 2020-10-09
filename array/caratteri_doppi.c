#include <stdio.h>

#define MAX 5

int main(){

	char s1[MAX], s2[2*MAX];
	int i, j, size1, size2;

	size1 = 0;
	scanf("%c", &s1[size1]);

	while(size1 < MAX && s1[size1] != '\n'){
		size1++;
		if(size1 < MAX)
			scanf("%c", &s1[size1]);
	}


	
	for(i = 0, size2 = 0; i < size1; i++, size2++){
		
		if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' ||s1[i] == 'u' ||
		   s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' ||s1[i] == 'U'){

		   s2[size2] = s1[i];
		   size2++;
		}
		
		s2[size2] = s1[i];
	}

	for(i = 0; i < size2; i++){
		printf("%c", s2[i]);
	}

	printf("\n");


	return 0;
}