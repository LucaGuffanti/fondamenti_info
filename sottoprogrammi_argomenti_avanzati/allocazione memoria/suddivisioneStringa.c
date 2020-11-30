#include <stdio.h>
#include <stdlib.h>

#define MAXS 50

void dividiStringa(char *, char **, char **);

int main(){

	char str[MAXS + 1];
	char *sub1, *sub2;
	
	scanf("%[^\n]", str);

	dividiStringa(str, &sub1, &sub2);
	if(sub1 && sub2){
		printf("%s %s\n", sub1, sub2);
		free(sub1);
		free(sub2);
	}

	return 0;
}

void dividiStringa(char *str, char **sub1, char **sub2){
	int len, dim1, dim2, i;

	for(len = 0; str[len] != '\0'; len++);

	dim1 = len/2;
	dim2 = len - dim1;

	*sub1 = malloc(sizeof(char) * (dim1 + 1)); /*il +1 tiene conto del \0*/

	if(*sub1){

		*sub2 = malloc(sizeof(char) * (dim2 + 1));

		if(*sub2){

			for(i = 0; i < dim1; i++, str++){
				*(*sub1 + i) = *str;
			}

			*(*sub1 + i) = '\0';

			for(i = 0; i < dim2; i++, str++){
				*(*sub1 + i) = *str;
			}

			*(*sub2 + i) = '\0';

		}else{
			free(*sub1);
			*sub1 = NULL:
			printf("errore di allocazione della stringa 2\n");
			
		}
	}else{
		*sub2 = NULL;
		printf("errore di allocazione della stringa 1\n");
		
	}

	for()

}