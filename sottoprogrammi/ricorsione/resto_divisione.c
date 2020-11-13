#include <stdio.h>

void divisione(int , int, int *, int *);

int main(){
    int n, m, resto, risultato;

    scanf("%d%d", &n, &m);

    resto = 0;
    risultato = 0;

    divisione(n, m, &resto, &risultato);

    printf("%d %d", risultato, resto);
    return 0;
}

void divisione(int n, int m, int *risultato, int *resto){
    
    if(n < m){
        /*caso base*/
        *risultato = 0;
        *resto = n;
    }else{
        /*caso ricorsivo*/
        divisione(n - m, m, risultato, resto);
        *risultato = *risultato + 1;

    }


    
}