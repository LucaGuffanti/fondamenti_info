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