#include <stdio.h>

#define SEC_IN_MIN 60
#define MIN_IN_ORE 60
#define ORE_IN_GG 24

#define N_INTERVALLI 2

typedef struct{

	int sec;
	int min;
	int ore;
	int giorni;
	
} intervallo_t ;

int main(){

	intervallo_t tempi[N_INTERVALLI], totale;
	int i;

	for(i = 0; i < N_INTERVALLI; i++){
		
		do{	
			scanf("%d", &tempi[i].sec);
			scanf("%d", &tempi[i].min);
			scanf("%d", &tempi[i].ore);
		}while(tempi[i].sec >= 60 || tempi[i].min >= 60 || tempi[i].ore >= 24 );

		tempi[i].giorni = 0;
	}


	totale.sec = 0;
	totale.min = 0;
	totale.ore = 0;
	totale.giorni = 0;

	for(i = 0; i < N_INTERVALLI; i++){

		totale.sec = totale.sec + tempi[i].sec;
		totale.min = totale.min + tempi[i].min;
		totale.ore = totale.ore + tempi[i].ore;
	}

	totale.min = totale.min + (totale.sec / SEC_IN_MIN);
	totale.sec = totale.sec % SEC_IN_MIN;
	totale.ore = totale.ore + (totale.min / MIN_IN_ORE);
	totale.min = totale.min % MIN_IN_ORE;
	totale.giorni = totale.giorni + (totale.ore / ORE_IN_GG);
	totale.ore = totale.ore % ORE_IN_GG; 

	printf("%d giorni %d ore %d minuti %d secondi\n", totale.giorni, totale.ore, totale.min, totale.sec );

	return 0;

}