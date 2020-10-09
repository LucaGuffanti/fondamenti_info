#include <stdio.h>

#define DIM 10

int main(){

	int s1[DIM], s2[DIM];
	int i, j, visto, somma;

	for(i = 0; i < DIM; i++){
		scanf("%d", &s1[i]);
	}

	for(i = 0; i < DIM; i++){
		scanf("%d", &s2[i]);
	}

	/*
	Per verificare che sia una permutazione, 
	azzero il vettore l'elemento i-esimo del vettore s1 se trovo una coppia che combacia,
	eseguendo una sottrazione. Agendo così sul vettore e terminando prematuramente il ciclo qualora si trovi 
	una coppia esatta, elimino la possibilità di errore perché l'elemento appena azzerato non verrà più
	controllato.
	Al termine per verificare che si tratti di una permutazione, eseguo una somma degli elementi del primo vettore:
	se è 0, allora tutti si sono cancellati e quindi si tratta di una permutazione, altrimenti non lo è!

	*/
	for(i = 0; i < DIM; i++){
		for(j = 0, visto = 0; j < DIM && !visto; j++){
			if(s1[i] == s2[j]){
				s1[i] = s1[i] - s2[j];
				visto = 1;
			}
		}
	}

	for(i = 0, somma = 0; i < DIM; i++){
		somma = somma + s1[i];
	}

	if(!somma){
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