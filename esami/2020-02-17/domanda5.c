#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
    int n;
    struct nodo_ *next;
} nodo_t;

nodo_t* inserireCoda(nodo_t*, int );
int lunghezza(nodo_t*);
nodo_t* calcolaMediaIesima(nodo_t*);
void visualizza(nodo_t*);

int main(){
    nodo_t *l1, *l2;

    l1 = NULL;
    l2 = NULL;

    l1 = inserireCoda(l1, 1);
    l1 = inserireCoda(l1, 5);
    l1 = inserireCoda(l1, 4);
    l1 = inserireCoda(l1, 7);
    l1 = inserireCoda(l1, 6);
    l1 = inserireCoda(l1, 4);
    l1 = inserireCoda(l1, 6);
    l1 = inserireCoda(l1, 3);
    l1 = inserireCoda(l1, 6);

    visualizza(l1);

    l2 = calcolaMediaIesima(l1);

    visualizza(l2);

    return 0;
}


nodo_t* inserireCoda(nodo_t *h, int num){
    nodo_t *tmp;
    nodo_t *curr;

    tmp = malloc(sizeof(nodo_t));
    if(tmp){
        tmp->n = num;
        tmp->next = NULL;
        if(h){
            for(curr = h; curr->next; curr = curr->next);
            curr->next = tmp;
        }else{
            h = tmp;
        }
    }else{
        printf("errore\n");
    }

    return h;
}

int lunghezza(nodo_t *h){
    int l;
    for(l = 0; h; l++, h = h->next);

    return l;
}

void visualizza(nodo_t *h){
    for(; h; h = h->next){
        printf("%d\n", h->n);
    }
}

nodo_t* calcolaMediaIesima(nodo_t *l1){
    int indiceTesta, indiceCoda, ripetizioni,  len, i;
    int media;
    nodo_t *l2;
    nodo_t *elem1, *elem2;

    len = lunghezza(l1);
    l2 = NULL;

    for(ripetizioni = 0; ripetizioni < len/2; ripetizioni++){
        
        indiceTesta = ripetizioni;
        for(elem1 = l1, i = 0; elem1 && i < indiceTesta; i++, elem1 = elem1->next);
        indiceCoda = len - indiceTesta - 1;
        for(elem2 = l1, i = 0; elem2 && i < indiceCoda; i++, elem2 = elem2->next);
        
        media = (elem1->n + elem2->n)/2;
        l2 = inserireCoda(l2, media);
    }
    if(len%2 != 0){
        for(elem1 = l1, i = 0; elem1 && i < (len/2); i++, elem1 = elem1->next);
        l2 = inserireCoda(l2, elem1->n);
    }
    
    return l2;
}