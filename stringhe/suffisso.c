#include <stdio.h>
#include <string.h>


#define DIM 30

int main(){

	char s[DIM + 1], suff[DIM + 1];
	int i, j, n, slen;

	scanf("%s", s);
	scanf("%d", &n);

	slen = strlen(s);

	if(n < slen){

		for(i = n, j = 0; s[i] != '\0'; i++, j++){
			suff[j] = s[i];
		}
		suff[j] = '\0';

	}else{

		for(i = 0; i < slen; i++){
			suff[i] = s[i];
		}

		suff[i] = '\0';

	}


	printf("%s\n", suff);

	return 0;

}

/*
ciao\0
2
slen = 4

*/