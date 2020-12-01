#include <stdio.h>
#include <stdlib.h>

#define MAXLIBRI 100
#define MAXS 50
typedef struct {

    int id;
    char autore[MAXS+1];
    char titolo[MAXS+1];
    int prezzo;

    

} libro_t;

typedef struct{
    
    libro_t libri[MAXLIBRI];
    int quanti;

} libreria_t;

libro_t* libriCosto(libreria_t [], int, int, int*);

libro_t* libriCosto(libreria_t bib[], int prezzo, int dim, int *dimOut){
    int i, j, k;
    libro_t *listaFinale;
    *dimOut = 0;

    for(i = 0; i < dim; i++){
        for(j = 0; j < bib[i].quanti; j++){
            if(bib[i].libri[j].prezzo < prezzo){
                (*dimOut)++;
            }
        }
    }

    if((*dimOut)>0){

        listaFinale = malloc(sizeof(libro_t) * (*dimOut));

        if(listaFinale){
            for(i = 0, k = 0; i < dim; i++){
                for(j = 0; j < bib[i].quanti; j++){
                    if(bib[i].libri[j].prezzo < prezzo){
                        listaFinale[k] = bib[i].libri[j];
                        k++;
                    }
                }
            }
        }else{
            printf("Errore nell'allocazione\n");
            *dimOut = 0;
        }
    }else{
        listaFinale = NULL;
    }

    return listaFinale;
}