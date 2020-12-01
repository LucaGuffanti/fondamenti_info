#include <stdio.h>

#define MAXS 30

int main(){

	char fn1[MAXS + 1], fn2[MAXS + 1];
	FILE *fp1, *fp2;

	char c1, c2;
	int uguali;

	scanf("%s %s", fn1, fn2);

	fp1 = fopen(fn1, "r");

	if(fp1){

		fp2 = fopen(fn2, "r");

		if(fp2){

			uguali = 1;
			fscanf(fp1, "%c", &c1);
			fscanf(fp2, "%c", &c2);

			while(!feof(fp1) && !feof(fp2) && uguali){
				if(c1 != c2)
					uguali = 0;

				fscanf(fp1, "%c", &c1);
				fscanf(fp2, "%c", &c2);
			}

			if(!feof(fp1) || !feof(fp2)){
				uguali = 0;
			}

			if(uguali){
				printf("File uguali\n");
			}else{
				printf("File diversi\n");
			}

			fclose(fp2);

		}else{
			printf("Errore nel secondo file\n");
		}

		fclose(fp1);

	}else{
		printf("Errore nel primo file\n");
	}

	return 0;
}