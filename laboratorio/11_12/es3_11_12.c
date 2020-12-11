/*
ES3. Scrivere un sottoprogramma che riceve come parametri due interi n e b, con b sicuramente compreso tra 1 e 9 estremi inclusi. Il
sottoprogramma visualizza tutti i numeri, in ordine crescente, che possono essere generati in base b su n cifre.
Per esempio se il sottoprogramma riceve in ingresso i valori n=3 e b=2, stampa a video "000, 001, 010, 011, 100, 101, 110, 111".
Scrivere un programma che chiede all'utente due valori interi n e b ed invoca il sottoprogramma sopra definito.
NOTA: nel caso si realizzi un sottoprogramma ricorsivo è possibile passare anche ulteriori parametri ritenuti necessari.
*/

#include <stdio.h>

void generaNumeri(int, int); 

int main(){
    int n, b;
    
    scanf("%d %d", &n, &b);
    
    generaNumeri(n, b);

    return 0;
}

void generaNumeri(int n, int b){
    int nMax;
    int numero, cifra, codificato, conta;
    int i;
    int v[n];

    for(i = 0; i < n; i++){
        v[i] = 0;
    }
    /*il numero massimo partendo da 0 è pari
    a b^n - 1*/
    for(i = 0, nMax = 1; i < n; i++, nMax*=b);
    nMax--;
    for(i = 0; i <= nMax; i++){
        numero = i;
        if(numero == 0){
            for(conta = 0; conta < n; conta++){
                printf("%d", v[conta]);
            }
            printf("->%d\n", i);
        }else{
            conta = 0;
            while(numero > 0){
                cifra = numero%b;
                numero = numero/b;
                v[conta] = cifra;
                conta++; 
            }
            for(conta = n-1; conta >= 0; conta--){
                printf("%d", v[conta]);
            }
            printf("->%d\n", i);

            for(conta = 0; conta < n; conta++){
                v[conta] = 0;
            }
        }
    }
}