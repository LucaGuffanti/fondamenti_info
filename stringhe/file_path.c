#include <stdio.h>

#define DIM 50
#define SEP '/'

int main(){

	char path[DIM + 1], file[DIM + 1];
	int start, i;

	scanf("%s", path);

	for( i = 0; path[i] != '\0'; i++){
		
		if(path[i] == SEP){
			start = i + 1;
		}

	}

	for( i = start; path[i] != '\0'; i++){

		file[i - start] = path[i];
	}

	file[i - start] = '\0';

	printf("%s\n", file);

	return 0;
}