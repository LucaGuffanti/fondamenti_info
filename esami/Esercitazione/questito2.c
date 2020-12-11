#include <stdio.h>

#define MINLEN 8
#define CONSEC 3

int verifica(char[]);

int main(int argc, char *argv[]){

	int esito;
	if(argc == 2){
		esito = verifica(argv[1]);
		printf("Esito: %d\n", esito);
	}else{
		printf("Errore negli argomenti\n");
	}

	return 0;
}

int verifica(char password[]){
	int i, j, cc, cs, uguali, noconsec;

	for(i = 0, cc = 0, cs = 0, noconsec = 1; password[i]!='\0' && noconsec; i++){
		if(password[i] >= '0' && password[i] <= '9'){
			cc++;
		}else if(!((password[i] >= 'A' && password[i] <= 'Z')||(password[i] >= 'a' && password[i] <= 'z'))){
			cs++;
		}
		for(j = 0; uguali = 1; j < CONSEC && uguali && password[i+j]!='\0'; j++){
			if(password[i] != password[i+j]){
				uguali = 0;
			}
		}
		if(uguali && j == CONSEC){ /*mi serve che tutte e 3 i caratteri siano uguali*/
			noconsec = 0;
		}
	}

	return cc && cs && i>=MINLEN && noconsec;
}