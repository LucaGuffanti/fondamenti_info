#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rep(char[], int);

int main(int argc, char* argv[]){
	char* s;
	int n;

	if(argc == 3){

		s = rep(argv[1], atoi(argv[2]));
		printf("%s\n", s);
	}else{
		printf("Errore negli argomenti\n");
	}
	return 0;
}

char* rep(char str[], int n){
	int dim, i, ripetizioni;
	char *s;


	dim = strlen(str);
	s = malloc(sizeof(char)*dim*n + 1);
	if(s){
		for(ripetizioni = 0; ripetizioni < n; ripetizioni++){
			for(i = 0; i < dim; i++){
				s[i + dim*ripetizioni] = str[i];
			}
		}

		s[dim*ripetizioni] = '\0';
	}else{
		printf("Errore nell'allocazione della stringa\n");
	}

	return s;
}