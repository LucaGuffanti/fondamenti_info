/*
ES1 - Realizzare un sottoprogramma che riceve come parametro una
stringa di testo composta da parole in caratteri minuscoli ciascuna
di lunghezza indefinita e separate da singoli spazi. Il
sottoprogramma modifica la stringa secondo la procedura qui sotto
riportata e poi ne stampa all'utente la nuova versione.
Procedura: ogni parola all'interno della stringa di testo viene
invertita, l'ultima lettera diventa la prima e viceversa.
Esempio
Input: ciao come stai
Output: oaic emoc iats
Scrivere un programma che chiede all'utente una stringa di al
massimo 250 caratteri, invoca su di essa il sottoprogramma sopra
definito e stampa a video il risultato
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 250

void invertiParole(char []);


int main(){

    char str[MAXS+1];
    int i;
    scanf("%[^\n]", str);

    invertiParole(str);

    return 0;
}

void invertiParole(char str[]){
    int i, j, cont, newWord, end;
    char *str2;

    str2 = NULL;
    /*scorrendo ogni carattere, anche nel caso del carattere terminatore*/
    for(i = 0, cont = 0, end = 0, newWord = 0; !end; i++){
        /*verifico se può costituire una parola*/
        if((str[i] >= 'a' && str[i] <= 'z')){
            cont++;
        }
        /*se è diverso da una lettera, vuol dire che una parola è appena terminata*/
        else if(str[i] == '\0'){
            newWord = 1;
            end = 1;
        }
        else{
            newWord = 1;
        }
        /*quindi mi concentro sulla parola appena finita*/
        if(newWord){

            /*alloco dinamicamente in memoria una stringa, ma non mi serve il terminatore*/
            str2 = malloc(sizeof(char) * cont);

            if(str2){

                /*salvo perciò nella seconda stringa la parola della prima*/
                for(j = 0; j < cont; j++){

                    /*non c'è bisogno dello shift di 1 a destra, perché nel ciclo in cui entro, i è già incrementata*/
                    str2[j] = str[i - cont + j];
                }
                /*quindi inverto proprio la stringa, salvandola direttamente nella stringa iniziale*/
                for(j = 0; j < cont; j++){
                    str[i - cont + j] = str2[cont - j - 1];
                }
                /*e libero la memoria appena occupata, per una nuova iterazione*/
                free(str2);
            }else{
                printf("Errore!\n");
                return;
            }

            newWord = 0;
            cont = 0;
        }
    }
    /*quando esco, vuol dire che ho superato di uno il carattere terminatore, e lo riassegno per sicurezza, stampando il risultato*/
    i--;
    str[i] = '\0';
    printf("%s", str);
    printf("\n");
}