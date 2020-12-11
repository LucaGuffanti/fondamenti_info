/*
ES 2
1. Scrivere un sottoprogramma C che riceve come parametri un magazzino di componenti MAG, un manuale di istruzioni MAN ed
un numero intero X. Il sottoprogramma verifica se è possibile costruire X mobili relativi al manuale MAN ricevuto come
parametro e prelevando i componenti dal magazzino MAG; in caso affermativo il sottoprogramma restituisce 1 altrimenti 0.
2. Scrivere un programma che riceve come argomenti i nomi di due file binari, contenenti rispettivamente i dati di un libretto di
istruzioni (una variabile di tipo istruzioni_t) e di un magazzino (una variabile di tipo magazzino_t), ed un numero N. Il programma
legge dai file i dati salvandoli in due variabili di tipo istruzioni_t e magazzino_t, ne visualizza i due contenuti ed esegue la
chiamata al sottoprogramma precedentemente definito e stampa a video il risultato dell'elaborazione. Il programma deve gestire
opportunamente tutti i possibili casi di errore.
Come test, forniamo i file istrN.bin, magN.bin, con N=1,2,3. Qui di seguito mostriamo gli output omettendo le stampe relative a codici,
descrizioni e quantità, lasciando quindi solo l'output del sottoprogramma.
./ikea istr1.bin mag1.bin 1
Output: 1
./ikea istr1.bin mag1.bin 2
Output: 0
./ikea istr2.bin mag2.bin 0
Output: 1
./ikea istr2.bin mag2.bin 1
Output: 0
./ikea istr3.bin mag3.bin 3
Output: 1
./ikea istr3.bin mag3.bin 4
Output: 0
./ikea istr2.bin mag3.bin 0
Output: 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXS 100
#define MAXC 200

typedef struct{

    int codice;
    char nome[MAXS + 1];
    int quantita;
} componente_t;

typedef struct{

    char nome[MAXS + 1];
    char indirizzo[MAXS + 1];
    componente_t componenti[MAXC];
    int n_componenti;
} magazzino_t;

typedef struct{

    int codice;
    char descrizione[MAXS + 1];
    float costo;
    componente_t componenti[MAXC];
    int n_componenti;
} istruzioni_t;


int costruibile(magazzino_t, istruzioni_t, int);

int main(int argc, char *argv[]){
    magazzino_t m;
    istruzioni_t i;
    FILE* fpmag;
    FILE* fpist;
    int result;
    if(argc == 4){
        /*leggere da file*/
        fpmag = fopen(argv[2], "rb");
        if(fpmag){
            fpist = fopen(argv[1], "rb");
            if(fpist){

                fread(&i, sizeof(istruzioni_t), 1, fpist);
                fread(&m, sizeof(magazzino_t), 1, fpmag);

                result = costruibile(m, i, atoi(argv[3]));
                printf("Output: %d\n", result);

                fclose(fpmag);
                fclose(fpist);
            }else{
                printf("Errore nell'apertura del file istruzioni");
            }
        }else{
            printf("Errore nell'apertura del file magazzino\n");
        }
    }else{
        printf("Errore argv\n");
    }

    return 0;
}

int costruibile(magazzino_t mag, istruzioni_t man, int x){
    int esito, somma, singolo_componente, i, j;
    printf("\n\n\nOggetto da produrre: %d, %s", man.codice, man.descrizione);
    printf("\nRicerca nei magazzini disponibili\n\n");
    for(i = 0, esito = 1; i < man.n_componenti && esito; i++){
        
        for(j = 0, singolo_componente = 1; j < mag.n_componenti && singolo_componente; j++){
        
            if(!strcmp(mag.componenti[j].nome, man.componenti[i].nome)){
                printf("%s in magazzino %s: %d, richiesti: %d\n",mag.componenti[j].nome, mag.nome, mag.componenti[j].quantita , man.componenti[i].quantita*x);
                if(man.componenti[i].quantita != 0){
                    if(!(mag.componenti[j].quantita / man.componenti[i].quantita >= x)){
                        singolo_componente = 0;
                        printf("Componenti in numero inferiore al richiesto\n");
                    }else{
                        printf("Componenti in numero maggiore o uguale al richiesto\n");
                    }
                }
            }
        }
        if(!singolo_componente){
            esito = 0;
            printf("Non costruibile\n");
        }
    }
    if(esito){
        printf("\n____________________________\nCostruibile\n\n");
    }
    
    return esito;
}