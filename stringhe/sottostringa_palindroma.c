#include <stdio.h>
#include <string.h>

#define DIM 100
#define MIN_SOTT 2



/*
	SPIEGAZIONE

	°DIM indica la dimensione massima della stringa di testo.

	°MIN_SOTT indica la dimensione minima di una sottostringa.


	°str[] contiene la stringa introdotta.
	
	°sott[] contiene le sottosequenze di dimensione man mano incrementata.
	
	°i scorre tutti gli elementi di str.
	
	°j associa a sott[] l'elemento corrispondente di str[].

	°k scorre tutti gli elementi di sott[] per verificare la proprietà della sottostringa.

	°n contiene la dimensione massima della sottosequenza, ed è introdotta dall'utente.
	
	°sottlen contiene la dimensione variabile di sott[].
	
	°slen contiene la dimensione di str[].
	
	°palindromo è una variabile logica, utile per la verifica della proprietà.
	
	°conta registra la quantità di sottostringhe palindrome di una data dimensione.


	il programma richiede la stringa e la dimensione massima della sottostringa.

	all'incrementare di sottlen, che va da 2 a n compreso

		si scorre l'intera stringa di testo

			per ogni carattere si identifica ogni sottostringa di dimensione sottlen, con il carattere come primo elemento

			si verifica che questa sia palindroma

			si stampano i risultati

*/

int main(){

	char str[DIM + 1], sott[DIM + 1];
	int i, j, k, n, sottlen, slen, palindromo, conta;


	scanf("%s %d", str, &n);

	slen = strlen(str);

	for(sottlen = MIN_SOTT; sottlen <= n; sottlen++){
		
		/*Si scorre l'intera stringa*/
		for(i = 0, conta = 0; i < slen - MIN_SOTT + 1; i++){

			/*Si costruisce la sottosequenza*/
			for(j = 0; j < sottlen; j++){

				sott[j] = str[i + j];

			}
			
			/*Si verifica che la sottostringa sia palindroma*/	
			for(k = 0, palindromo = 1; k < sottlen/2 && palindromo; k++){

				if(sott[k] != sott[sottlen - 1 - k]){

					palindromo = 0;

				}else{

					palindromo = 1;
				}
				
			}

			/*Se lo è, questa viene stampata, e il contatore aumenta*/
			if(palindromo){

				conta++;
					
				printf("Sottostringa palindroma di DIM = %d: ", sottlen);

				for(k = 0; k < sottlen; k++){
		
					printf("%c", sott[k]);
				}

				printf("\n");

			}
			
		}

		/*Stampando, per ogni dimensione, il numero di sottostringhe palindrome con quella dimensione*/
		printf("Numero di sottostringhe di DIM = %d: %d\n\n", sottlen, conta);

	}


	return 0;
}