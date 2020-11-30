#include <stdio.h>
#include <string.h>

#define DIM 20
#define CHIAVE 3

char verificalettera(char l);

char cifra(char l);

char decifra(char l);


int main(){

	char messaggio[DIM + 1], cifrato[DIM + 1];
	int i;

	scanf("%s", messaggio);

	for(i = 0; messaggio[i] != '\0'; i++){
		
		cifrato[i] = cifra(messaggio[i]);
	}	

	cifrato[i] = '\0';

	printf("Messaggio cirfrato: %s\n", cifrato);

	for(i = 0; cifrato[i] != '\0'; i++){

		cifrato[i] = decifra(cifrato[i]);
	}

	cifrato[i] = '\0';

	printf("Messaggio decifrato: %s\n", cifrato);

	if(!strcmp(messaggio, cifrato)){

		printf("Il messaggio in chiaro e quello decifrato coincidono correttamente\n");
	}else{

		printf("Il messaggio in chiaro e quello decifrato non coincidono. C'e' stato un errore!\n");
	}	

	return 0;
}

char verificalettera(char l){

	int minuscola;

	if(l >= 'a' && l <= 'z'){
		
		minuscola = 1;
	}else{

		minuscola = 0;
	}

	return minuscola;
}

char cifra(char l){
	
	if (verificalettera(l)){
		if(l + CHIAVE > 'z'){
			l = l + CHIAVE - 'z' + 'a' - 1; 
		}else{
			l = l + CHIAVE;
		}
	}
	return l; 
}

char decifra(char l){

	if (verificalettera(l)){
		if(l - CHIAVE < 'a'){
			l = l - CHIAVE + 'z' - 'a' + 1; 
		}else{
			l = l - CHIAVE;
		}
	}
	return l; 
}