#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


nodo_t* selezionaMaggiori(nodo_t *);

nodo_t* selezionaMaggiori(nodo_t *l){
    nodo_t *l2;

    l2 = NULL;
    if(l){
        for(; l->next; l = l->next){
            if(l->n > (l->next)->n)
                l2 = inserisciInCoda(l2, l->n);
        }

        l2 = inserisciInCoda(l2, l->n);
    }
    return l2;
}

/*
nodo_t* inserisciInCoda(nodo_t* h, int num){
    nodo_t *tmp;
    nodo_t *curr;

    tmp = malloc(sizeof(nodo_t*));

    if(tmp){
        tmp->n = num;
        tmp->next = NULL;

        if(h){
            for(curr = h; curr->next; curr = curr->next);
            curr->next = tmp;

        }else{
            tmp->next = h;
            h = tmp; 
        }

    }

    return h;

}


*/