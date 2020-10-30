/*es2 del laboratorio del 23/10*/

#include <stdio.h> 
#include <string.h>

#define SDIM 50

int main(){

	char s1[SDIM + 1], s2[SDIM + 1];
	int n, size, i;

	scanf("%s%d", s1, &n);

	size = strlen(s1);

	while(n < 0 || n > size){
		printf("Inserire nuovamente il passo\n");
		scanf("%d", &n);
	}

	for(i = 0; i < size; i++){
		
		if(i + n >= size){
			s2[i + n - size] = s1[i];
		}else{
			s2[i + n] = s1[i];
		}
	}

	s2[size] = '\0';

	printf("%s\n", s2);

	return 0; 
}