#include <stdio.h>
#include <stdlib.h>

#define FILENAME "lista.bin"

typedef struct nodo_{
    int n;
    struct nodo_* next;
} nodo_t;

nodo_t* inserisciInTesta(nodo_t*, int);
nodo_t* inserisciInCoda(nodo_t*, int);
void visualizza(nodo_t*);
void distruggi(nodo_t*);

int main(){

    nodo_t *h;
    int i, num;
    FILE *fp;

    h = NULL;

    for(i = 0; i < 5; i++){
        scanf("%d", &num);
        h = inserisciInCoda(h, num);
    }
/*
    fp = fopen(FILENAME, "wb");
    if(fp){

        nodo_t* tmp;
        tmp = h;
        while(tmp){
            fwrite(&(tmp->n), sizeof(int), 1, fp);
            tmp = tmp->next;
        }

        free(tmp);
        distruggi(h);
        fclose(fp);

    }else{
        printf("Errore nell'apertura del file");
    }

    h = NULL;

    fp = fopen(FILENAME, "rb");

    if(fp){

        fread(&num, sizeof(int), 1, fp);
        while(!feof(fp)){
            h = inserisciInTesta(h, num);
            fread(&num, sizeof(int), 1, fp);
        }

        visualizza(h);
        distruggi(h);
        fclose(fp);
    }else{
        printf("Errore nell'apertura del file\n");
    }
  */

    visualizza(h);  
    return 0;
}


nodo_t* inserisciInTesta(nodo_t *h, int num){
    
    nodo_t *tmp;

    tmp = malloc(sizeof(nodo_t));

    if(tmp){
        tmp->n = num;
        tmp->next = h;
        h = tmp;
    }else{
        printf("Errore nell'allocazione\n");
    }

    return h;
}

void visualizza(nodo_t* h){
    for(; h; h = h->next){
		printf("%d\n", h->n);
	}
    printf("\n");
}

void distruggi(nodo_t *h){
    nodo_t *tmp;
    while(h){
        tmp = h;
        h = h->next;
        free(tmp);
        
    }
}

nodo_t* inserisciInCoda(nodo_t* h, int num){
    nodo_t *tmp;
    nodo_t *curr;
    nodo_t *prec;

    tmp = malloc(sizeof(nodo_t));
    if(tmp){
        tmp->n = num;
        tmp->next = NULL;

        if(h){
            for(curr = h, prec = NULL; curr->next; curr = curr->next);

            curr->next = tmp;
        }else{
            tmp->next = h;
            h = tmp;  
        }
    }else{
        printf("Errore di allocazione\n");
    }

    return h;
}