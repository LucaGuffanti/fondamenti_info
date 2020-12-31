#include <stdio.h>

#define FILENAME "ris.txt"

int main(int argc, char* argv[]){
	int num, div, nDiv, contaNum;
	FILE* fp;

	fp = fopen(FILENAME, "w");
	if(fp){
		contaNum = 0;
        scanf("%d", &num);
        while(num > 0){
            for(div = 2, nDiv = 0; div < num; div++){
            	if(num%div == 0){
            		nDiv++;
            	}
            }
            contaNum++;
            fprintf(fp, "%d %d\n", num, nDiv);
        	scanf("%d", &num);
        }

        printf("%d\n", contaNum);
        fclose(fp);
	}else{
		printf("Errore nell'apertura del file\n");
	}

    return 0;
}