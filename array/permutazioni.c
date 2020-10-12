#include <stdio.h>

#define DIM 4

int main(){

	int s1[DIM], s2[DIM];
	int i, j, visto, zero, passato[DIM];

	for(i = 0; i < DIM; i++){
		scanf("%d", &s1[i]);
	}

	for(i = 0; i < DIM; i++){
		scanf("%d", &s2[i]);
	}

	for (i = 0; i < DIM; i++){
		passato[i] = 0;
	}

	/*
	Per verificare che sia una permutazione, 
	azzero il vettore l'elemento i-esimo del vettore s1 se trovo una coppia che combacia,
	eseguendo una sottrazione. Agendo così sul vettore e terminando prematuramente il ciclo qualora si trovi 
	una coppia esatta, elimino la possibilità di errore perché l'elemento appena azzerato non verrà più
	controllato.
	Inoltre, per evitare errori nel caso di ripetizioni, si associa agli elementi del secondo vettore un array con
	valori logici, che 'salva' quali elementi sono stati già analizzati.

	*/
	for(i = 0; i < DIM; i++){
		for(j = 0, visto = 0; j < DIM && !visto; j++){
			if(s1[i] == s2[j] && passato[j] == 0){
				s1[i] = 0;
				passato[j] = 1;
				visto = 1;
			}
		}
	}

	for(i = 0; i < DIM && zero; i++){
		zero = s1[i] == 0;
	}

	if(zero){
		printf("Permutazione!\n");

	}else{
		printf("Non Permutazione!\n");
	}

	return 0;
}

/*
	SIMULAZIONE

	1 2 3 0 0 4

	4 3 2 1 4 0

	i = 0
	j
	sizev
	conta



*/