#include <stdio.h>
#include <stdlib.h>

#define LOOPS 2

int main(){

    int n, k; /*qui è la dimensione del mio array*/
    int *a; /*puntatore all'array nella heap*/
    int i;


    for(k = 0; k < LOOPS; k++){
        
        scanf("%d",  &n);
        
        /*alloco dinamicamente il mio array*/
        a = malloc(sizeof(int) * n); /*ha come tipo di ritorno (void *), quindi devo
        eseguire un cast a int, che però è facoltativo perché con l'assegnamento diventa implicito*/

        if(a){ /*la memoria ha un limite, se l'allocazione fallisce ho un ritorno di NULL*/
            for(i = 0; i < n; i++){
                scanf("%d", (a + i));
            }
            for(i = 0; i < n; i++){
                printf("%d", *(a + i));
            }

            /*questo mi permette di rilasciare la memoria*/

            free(a); 
        }else{
            printf("Errore di allocazione\n");
        }


    }
    /*esistono anche altre funzioni
    calloc: alloca e inizializza a 0
    ralloc: alloco nuovamente un array già allocato
    */
    return 0;
}