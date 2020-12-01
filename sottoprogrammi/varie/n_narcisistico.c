#include <stdio.h>

#define BASE 10
#define ESP 4

void narcisistico(int [], int [], int);

void narcisistico(int a[], int b[], int dim){
    int i, somma, cifra, narc, n, pot, j;

    for(i = 0; i < dim; i++){
        somma = 0;
        n = a[i];
        while(n > 0){
            
            cifra = n%BASE;
            n = n/BASE;

            /*calcolo la potenza */
            for(j = 0, pot = 1; j < ESP; j++){
                pot = pot * cifra;
            }

            somma = somma + pot;
        }

        narc = somma == a[i];
        /*

        if(narc){
            b[i] = 1;
        }else{
            b[i] = 0;
        }
        
        */
        b[i] = (somma == a[i]);
    }
}