#include <stdio.h>
#include <stdlib.h>

#define FILENAME "dizionario.txt"
#define MAXS 25

int anagramma(char [], char []);
int anagramma2(int, int);

int dimmiAnagrammi(char [], char []);
int dimmiAnagrammi2(char [], char []);

int dimmiAnagrammi(char fn[], char vocabolo[]){
	FILE *fp;
	int cont;
	char str[MAXS + 1];

	fp = fopen(fn, "r");
	if(fp){
		cont = 0;
		fscanf(fp, "%s", str);
		while(!feof(fp)){

			if(anagramma(vocabolo, str)){
				conta++;
				printf("%s\n", str);
			}

			fscanf(fp, "%s", str);
		}

		fclose(fp);
	}else{
		printf("Errore nell'apertura\n");
		cont = -1;
	}

	return cont;
}




int dimmiAnagrammi2(char fn[], int num){
	FILE *fp;
	int cont;
	int read;

	fp = fopen(fn, "r");
	if(fp){
		cont = 0;
		fscanf(fp, "%d", &read);
		while(!feof(fp)){

			if(anagramma(num, read)){
				conta++;
				printf("%d\n", read);
			}

			fscanf(fp, "%d", read);
		}

		fclose(fp);
	}else{
		printf("Errore nell'apertura\n");
		cont = -1;
	}

	return cont;
}

/*char num[MAXS+1];
voc = itoa(num, voc, 10);
*/