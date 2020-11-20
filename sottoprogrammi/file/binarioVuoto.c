#include <stdio.h>

#define MAXS 30

int main(){

	char fn[MAXS + 1];
	FILE *fp;
	int n;
	char c;

	scanf("%s", fn);

	fp = fopen(fn, "rb");

	if(fp){
		n = fread(&c, sizeof(char), 1, fp);
		fclose(fp);
		if(n)
			printf("File non vuoto\n");
		else
			printf("File vuoto\n");
	}else{
		printf("Errore nell'apertura\n");
	}
	return 0;
}