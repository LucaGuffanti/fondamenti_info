/*Programma che calcola il coefficiente binomiale di n e k*/

#include <stdio.h>

/*definiamo il sottoprogramma che calcola il fattoriale generico di un numero*/
int fattoriale(int num);

int acquisisci();


int main(){

	int n, k;
	int f_n, f_k, f_nk, coeff;

	n = acquisisci();
	k = acquisisci();

	/*
	  Qui dovremmo quindi scrivere 3 volte lo stesso algoritmo, ma noi usiamo
	  i sottoprogrammi, per evitare la "ridondanza", usando la funzione matematica
	  del fattoriale.
	*/


	/*calcoliamo f_n = n!*/
	f_n = fattoriale(n); /*n è il parametro attuale*/
	
	/*calcoliamo f_k = k!*/
	f_k = fattoriale(k);
	
	/*calcoliamo f_nk = (n - k)!*/
	f_nk = fattoriale(n - k);

	coeff = f_n/(f_k * f_nk);

	printf("%d\n", coeff);

	return 0;

}

/*definiamo quindi la funzione*/

int acquisisci(){

	int num;

	scanf("%d", &num);

	while(num < 0){
		printf("Numero non negativo\n");
		scanf("%d", &num);
	}

	return num;
}

int fattoriale(int num){ /*num è il parametro formale*/

	int ris, i;

	for(i = 2, ris = 1; i <= num; i++)
		ris = ris * i;

	return ris;
}


