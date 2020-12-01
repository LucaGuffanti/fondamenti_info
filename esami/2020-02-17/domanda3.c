#include <stdio.h>

#define NC 5
#define NR 5

void filtra(float [][NC], float [][NC], int, int);

int main(){

    float image[NR][NC], filter[NR][NC];
    int nr, nc;

    for(nr = 0; nr < NR; nr++){
        for(nc = 0; nc < NC; nc++){
            scanf("%f", &image[nr][nc]);
        }
    }

    filtra(image, filter, NC, NR);

    for(nr = 0; nr < NR; nr++){
        for(nc = 0; nc < NC; nc++){
            printf("%.2f ", filter[nr][nc]);
        }
        printf("\n");
    }


    return 0;
}

void filtra(float im[][NC], float filter[][NC], int nr, int nc){
    int i, j, k, h;
    float somma;
    float media;

    for(i = 0; i < nr; i++){
        for(j = 0; j < nc; j++){
            for(k = -1, somma = 0; k < 2; k++){
                for(h = -1; h < 2; h++){
                    /*maggiore della dimensione -1, perché si conta da 0. RICORDARLO*/
                    if(!(i+k < 0 || j+h < 0 || i+k > nr-1 || j+h > nc-1)){
                        somma += im[i+k][j+h];
                    }
                }
            }
            media = somma/9;
            filter[i][j] = media;
        }
    }
}