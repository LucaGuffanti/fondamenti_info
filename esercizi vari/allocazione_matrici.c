39C75FY4#include <stdio.h>
#include <stdlib.h>

int main(){
    int **m;
    int righe;
    int colonne;
    int i, j;

    printf("Inserire le dimensioni della matrice:\n");
    scanf("%d%d", &righe, &colonne);

    /*allochiamo la memoria della matrice*/
    /*anzitutto alloco il puntatore ai puntatori*/
    m = malloc(sizeof(int*) * righe);
    /*ora alloco ogni riga*/
    for(i = 0; i < righe; i++){
        m[i] = malloc(sizeof(int) * colonne);
    }
    /*proviamo a mettere tutto a 0 e a stampare*/
    for(i = 0; i < righe; i++){
        for(j = 0; j < colonne; j++){
            m[i][j] = 0;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}