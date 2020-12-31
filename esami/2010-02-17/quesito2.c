#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
	char c;
	int i, cont;
	FILE *fp;

	if(argc == 3){
      	fp = fopen(argv[2], "r");
      	if(fp){
      		for(i = 0; argv[1][i] != '\0'; i++){
      			cont = 0;
      			fscanf(fp, "%c", &c);
      			while(!feof(fp)){
      				if(c == argv[1][i])
      					cont++;
      				fscanf(fp, "%c", &c);
      			}
      			printf("%c:  %d",argv[1][i], cont);
      		}
      		printf("\n");
      		fclose(fp);
      	}else{
      		printf("Errore nell'apertura del file\n");
      	}
	}else{
		printf("Errore negli argomenti\n");
	}

	return 0;
}