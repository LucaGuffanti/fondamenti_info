#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
    int num;
    struct nodo_ *next;
} nodo_t;

nodo_t* inserisciInCoda(nodo_t *, int);
int lunghezza(nodo_t*);
nodo_t* filtraLista(nodo_t*, int[]);
void visualizza(nodo_t*);
nodo_t* distruggi(nodo_t*);

int main(){

    nodo_t *l1;
    nodo_t *l2;
    int *seq;
    int n, seqDim,  i;

    l1 = NULL;
    l2 = NULL;
    
    scanf("%d", &n);
    while(n != 0){
        l1 = inserisciInCoda(l1, n);
        scanf("%d", &n);
    }

    seqDim = lunghezza(l1);
    
    seq = malloc(sizeof(int) * seqDim);
    if(seq){

        printf("Il vettore dovra' avere %d elementi\n", seqDim);

        for(i = 0; i < seqDim; i++){
            scanf("%d", &seq[i]);
            while(seq[i] < 0 || seq[i] > 1){
                printf("Array composto da soli 1 e 0. Inserire nuovamente il valore\n");
                scanf("%d", &seq[i]);
            }
        }

        l2 = filtraLista(l1, seq);

        visualizza(l1);
        for(i = 0; i < seqDim; i++){
            printf("%d ", seq[i]);
        }
        printf("\n");

        visualizza(l2);

        distruggi(l1);
        distruggi(l2);
        free(seq);

    }else{
        printf("Errore nell'allocazione di seq\n");
    }

    return 0;
}

nodo_t *inserisciInCoda(nodo_t *l1, int n){
    nodo_t *tmp;
    nodo_t *curr;

    curr = NULL;
    tmp = malloc(sizeof(nodo_t));
    if(tmp){
        tmp->next = NULL;
        tmp->num = n;
        if(l1){
            for(curr = l1; curr->next; curr = curr->next);
            curr->next = tmp;
        }else{
            l1 = tmp;
        }
    }else{
        printf("Errore nell'allocazione del nodo della lista\n");
    }

    return l1;
}

int lunghezza(nodo_t *l1){
    int len;
    for(len = 0; l1; l1 = l1->next, len++);
    return len;
}

void visualizza(nodo_t *l1){
    for(; l1; l1 = l1->next){
        printf("%d ", l1->num);
    }
    printf("\n");
}

nodo_t *distruggi(nodo_t *l1){
    nodo_t *tmp;
    while(l1){
        tmp = l1;
        l1 = l1->next;
        free(tmp);
    }
    return NULL;
}

nodo_t *filtraLista(nodo_t *l1, int seq[]){
    int i;
    nodo_t *curr;
    nodo_t *l2;

    l2 = NULL;
    
    for(i = 0, curr = l1; curr; curr = curr->next, i++){
        if(seq[i] == 1){
            l2 = inserisciInCoda(l2, curr->num);
        }
    }

    return l2;
}