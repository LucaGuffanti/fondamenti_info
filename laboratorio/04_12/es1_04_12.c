/*
Si realizzino i seguenti sottoprogrammi utilizzando la struttura
dati e funzioni fornite nei file lista.c e lista.h.
Scrivere un sottoprogramma estrai() che riceve come parametro una
lista dinamica di numeri interi detta l1, e un parametro intero
detto dispari. Il sottoprogramma restituisce un puntatore ad una
nuova lista l2 contenente gli elementi di l1 in posizione dispari se
il parametro dispari vale 1, o gli elementi in posizione pari se il
parametro dispari vale 0.
NOTA: con "posizione" si intende l'equivalente dell'indice se
stessimo parlando di vettori invece che di liste: il primo elemento
della lista ha indice zero (pari), il secondo elemento ha indice 1
(dispari), e così via.
Scrivere un sottoprogramma uguali() che verifica se due liste
ricevute come parametro sono uguali, cioè contengono la stessa
sequenza di numeri.
Scrivere un sottoprogramma stessoContenuto() che verifica se due
liste l1 ed l2 ricevute come parametro contengono gli stessi valori,
a prescindere dall'ordine; cioè se una lista è una permutazione
dell'altra. Suggerimento: perchè l1 sia permutazione di l2 basta
controllare che le due liste abbiano pari lunghezza e che ciascun
valore presente in l1 compaia sia in l1 che in l2 lo stesso numero
di volte. Si suggerisce inoltre di implementare anche
1) un sottoprogramma di ausilio conta() che riceve come parametri
una lista ed un valore intero, e conta e restituisce quante volte il
valore intero compare nella lista, ed
2) un sottoprogramma lunghezza() che restituisce la lunghezza di una
lista ricevuta come parametro.
Scrivere un sottoprogramma unisci() che riceve come parametri due
liste l1 ed l2. Il sottoprogramma crea e restituisce una nuova lista
concatenando il contenuto di l1 con quello di l2.
Scrivere un programma che carica dal file di testo "serie.txt" (il
cui nome è stato passato come argomento alla chiamata del programma)
una serie di lunghezza indefinita di numeri interi e li memorizza in
una lista lf. Il programma, invocando i sottoprogrammi sopra
definiti,
1) crea una nuova lista lp, contenente i valori in posizione pari
della lista lf.
2) crea una nuova lista ld, contenente i valori in posizione dispari
della lista lf.
3) verifica se lp è uguale a ld ed in caso negativo se almeno
contengono gli stessi numeri sebbene in ordine diverso. Il programma
stampa a video gli esiti dei test.
4) genera una nuova lista u in cui appaiono prima tutti gli elementi
di lf originariamente in posizione pari e poi gli elementi
originariamente in posizione dispari.
5) infine, visualizza (a) la lista di partenza, (b) la lista degli
elementi in posizione pari, (c) la lista degli elementi in posizione
dispari, (d) la nuova lista con gli elementi riordinati comespecificato.
Infine il programma termina deallocando tutta la memoria allocata.
*/


#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

nodo_t* estrai(nodo_t*, int);
int uguali(nodo_t*, nodo_t*);
int stessoContenuto(nodo_t*, nodo_t*);
int conta(nodo_t*, int);
int lunghezza(nodo_t*);
nodo_t* unisci(nodo_t*, nodo_t*);

int main(int argc, char *argv[]){

    FILE *fp;
    nodo_t *lf;
    nodo_t *lp;
    nodo_t *ld;
    nodo_t *u;
    int n, ug, contenuto;

    lf = NULL;
    lp = NULL;
    ld = NULL;

    if(argc == 2){

        fp = fopen(argv[1], "r");
        if(fp){
            
            fscanf(fp, "%d", &n);
            while(!feof(fp)){
                lf = inserisciInCoda(lf, n);
                fscanf(fp, "%d", &n);
            }

            lp = estrai(lf, 0);
            ld = estrai(lf, 1);

            ug = uguali(lp, ld);
            if(!ug){

                contenuto = stessoContenuto(lp, ld);
                if(contenuto){
                    printf("Liste con stessi elementi in ordine diverso\n");
                }else{
                    printf("Liste non sono nemmeno una permutazione\n");
                }
            }else{
                printf("Le due liste sono uguali\n");
            }

            u = unisci(lp, ld);

            visualizza(lf);
            visualizza(lp);
            visualizza(ld);
            visualizza(u);

            distruggiLista(lf);
            distruggiLista(lp);
            distruggiLista(ld);
            distruggiLista(u);

            fclose(fp);

        }else{
            printf("Errore nell'apertura\n");
        }
    }else{
        printf("Argomenti errati\n");
    }

    return 0;
}

nodo_t* estrai(nodo_t *l1, int dispari){
    
    nodo_t *l2;
    int i;
    
    l2 = NULL;

    if(dispari){
        for(i = 0; l1; l1 = l1->next, i++){
            if(i%2 == 1){
                l2 = inserisciInCoda(l2, l1->num);
            }
        }
    }else{
        for(i = 0; l1; l1 = l1->next, i++){
            if(i%2 == 0){
                l2 = inserisciInCoda(l2, l1->num);
            }
        }
    }

    return l2;
}

int uguali(nodo_t *l1, nodo_t *l2){
    nodo_t *curr1, *curr2;
    int ug;

    
    for(ug = 1; l1 && l2 && ug; l1 = l1->next, l2 = l2->next){
        if(l1->num != l2->num){
            ug = 0;
        }
    }
    
    return ug;
}

int lunghezza(nodo_t *l1){
    int l;
    
    for(l = 0; l1; l1 = l1->next, l++);

    return l;
}

int conta(nodo_t *l1, int n){
    int c;
    
    for(c = 0; l1; l1 = l1->next){
        if(l1->num == n){
            c++;
        }
    }

    return c;
}

int stessoContenuto(nodo_t *l1, nodo_t *l2){
    int l, contenuto;
    int num1, num2;

    /*verifico la stessa dimensione*/
    l = lunghezza(l1) == lunghezza(l2);

    /*ora verifico la possibile permutazione se la lunghezza è la stessa*/
    if(l){

        for(contenuto = 1; l1 && l2; l1 = l1->next, l2 = l2->next){
            num1 = conta(l1, l1->num);
            num2 = conta(l2, l2->num);

            if(num1 != num2){
                contenuto = 0;
            }
        }
    }else{
        contenuto = 0;
    }

    return contenuto;
}

nodo_t* unisci(nodo_t *l1, nodo_t *l2){
    nodo_t *l3;
    nodo_t *curr;

    l3 = NULL;
    for(curr = l1; curr; curr = curr->next){
        l3 = inserisciInCoda(l3, curr->num);
    }
    for(curr = l2; curr; curr = curr->next){
        l3 = inserisciInCoda(l3, curr->num);
    }

    return l3;
}