#include <stdio.h>
#include <stdlib.h>

#define MAXS 30
#define FILENAME "lista.bin"

typedef struct nodo{
    int numero;
    struct nodo* next;
} nodo_t;

nodo_t* inserisciInTesta(nodo_t*, int);
void salvaSuFile(nodo_t*);
nodo_t* caricaDaFile();
void stampa(nodo_t*);

int main(){
    nodo_t* h;

    h = NULL;
    h = inserisciInTesta(h, 1);
    h = inserisciInTesta(h, 2);
    h = inserisciInTesta(h, 3);
    h = inserisciInTesta(h, 4);
    h = inserisciInTesta(h, 5);
    h = inserisciInTesta(h, 6);

    stampa(h);

    salvaSuFile(h);

    h = caricaDaFile();

    stampa(h);
    
    return 0;
}

nodo_t* inserisciInTesta(nodo_t* h, int num){
    nodo_t* tmp;

    if(tmp = malloc(sizeof(nodo_t))){
        tmp->next = h;
        tmp->numero = num;
        h = tmp;
    }else{
        printf("Errore\n");
    }
    return h;
}

void salvaSuFile(nodo_t* h){
    FILE* fp;
    int num;
    if(fp = fopen(FILENAME, "wb")){
        for(; h; h = h->next){
            num = h->numero;
            fwrite(&num, sizeof(int), 1, fp);
        }
        fclose(fp);
    }else{
        printf("Errore\n");
    }
}

nodo_t* caricaDaFile(){
    nodo_t* h;
    int tmp;
    FILE* fp;
    printf("Mi fermo qua\n");
    h = NULL;
    if(fp = fopen(FILENAME, "rb")){
        fread(&tmp, sizeof(int), 1, fp);
        while(!feof(fp)){
            h = inserisciInTesta(h, tmp);
            fread(&tmp, sizeof(int), 1, fp);
        }
        fclose(fp);
    }else{
        printf("Errore\n");
    }
    return h;
}

void stampa(nodo_t* h){
    for(; h; h = h->next)
        printf("%d", h->numero);
    printf("\n");
}