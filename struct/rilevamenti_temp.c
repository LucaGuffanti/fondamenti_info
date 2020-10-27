#include <stdio.h>

#define STRDIM 8
#define MAXR 100
#define MINTEMP 22

typedef struct{

	int piano;
	char ora[STRDIM + 1];
	int temperatura;

} rilevamento_t;


int main(){

	rilevamento_t ril[MAXR];
	int i, piano, numril, prec;

	do{
		printf("Numero di rilevamenti:\n");
		scanf("%d", &numril);

	}while(numril <= 0 || numril > MAXR);

	printf("Inserire dati\n");

	for(i = 0; i < numril; i++){
		scanf("%d %s %d", &ril[i].piano, ril[i].ora, &ril[i].temperatura);
	}


	printf("Indica il piano da analizzare: \n");
	scanf("%d", &piano);

	prec = -1;

	for(i = 0; i < numril; i++){
		if(ril[i].piano == piano){
			if(prec == -1 && ril[i].temperatura < MINTEMP){
				prec = i;
				printf("%s -> ", ril[i].ora);
			}
			else if(prec != -1 && ril[i].temperatura < MINTEMP){
				prec = i;
			}
			else if(prec != -1 && ril[i].temperatura >= MINTEMP){
				printf("%s\n", ril[prec].ora);
				prec = -1;
			}
		}
	}

	if(prec != -1){
		printf("%s\n", ril[prec].ora);
	}


	return 0;
}