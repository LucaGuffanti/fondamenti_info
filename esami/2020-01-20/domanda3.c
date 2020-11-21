/*programma non ancora completabile*/

#include <stdio.h>

#define MAXS 30 

int main(){

	char filename[MAXS + 1];
	FILE *fp;
	int cifre, decine, num;

	scanf("%s", filename);

	fp = fopen(filename, "r");

	if(fp){

		fscanf(fp, "%d", &num);

		while(!feof(fp)){

			cifre = num % 10;
			decine = (num / 10) % 10;

			if(decine == 2 * cifre && decine != 0){
				printf("%d\n", num);
			}
			cifre = 0;
			decine = 0;

			fscanf(fp, "%d", &num);
		}

	}else{
		printf("Errore di apertura\n");
	}
}