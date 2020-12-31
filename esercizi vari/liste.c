#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
    int num;
    struct nodo_ *next;
} nodo_t;

int lunghIterativa(nodo_t*);
int lunghRicorsiva(nodo_t*);
nodo_t* insTesta(nodo_t*, int);

int main(){
    nodo_t *h;
    h = NULL;

    h = insTesta(h, 1);
    h = insTesta(h, 1);
    h = insTesta(h, 1);
    h = insTesta(h, 1);

    printf("%d, %d", lunghRicorsiva(h), lunghIterativa(h));
    return 0;
}


int lunghIterativa(nodo_t *h){
    int l;
    for(l = 0; h; h = h->next, l++);
    return l;
}

int lunghRicorsiva(nodo_t *h){
    if(h->next == NULL)
        return 1;
    else
        return 1 + lunghRicorsiva(h->next);
}

nodo_t* insTesta(nodo_t *h, int n){
    nodo_t *tmp;

    tmp = malloc(sizeof(nodo_t));
    if(tmp){
        tmp->num = n;
        tmp->next = h;
        h = tmp;
    }else{
        printf("Errore nell'allocazione\n");
    }

    return h;
}