#include <stdio.h>
#include <string.h> 

#define MAXS 30

int main(){

	FILE *fp;
	char fn[MAXS + 1];
	char c;
	int nr, nc, np;

	scanf("%s", fn);

	fp = fopen(fn, "r");

	if(fp){
		fscanf(fp, "%c", &c);
	
		if(!feof(fp)){
			
			nr = 1;
			nc = 0;
			np = 0;

			while(!feof(fp)){

				if(c != ' ' && c != '\n' && c!= '\r' /*per windows*/){
					nc++;
				}
				else if(c == ' ' || (c == '\n' && nc > 0)){
					np++;
				}
				if(c == '\n'){
					printf("Riga %d: %d caratteri, %d parole\n", nr, nc, np);
					nr++;
					nc = 0;
				}

				fscanf(fp, "%c", &c);
			}


		}else{
			printf("File vuoto\n");
		}
		
		fclose(fp);

	}else{
		printf("Errore nell'apertura del file\n");
	}

	return 0;
}