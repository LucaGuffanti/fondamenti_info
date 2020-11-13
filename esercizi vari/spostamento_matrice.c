#include <stdio.h>
#define DIM 5


void spostaPuntatore(int *, int, int);
void print(int *, int, int);

int main(){

    int m[DIM][DIM];
    int i, j;

    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            m[i][j] = 0;
        }
    }

    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    spostaPuntatore(&m[0][0], DIM, DIM);

    print(&m[0][0], DIM, DIM);

    return 0;
}

void spostaPuntatore(int *m, int cols, int rows){
    int xPos, yPos;
    int inserimenti;
    int i;

    scanf("%d", &inserimenti);
    for(i = 0; i < inserimenti; i++){
        printf("Inserire le coordinate:\n");
        scanf("%d%d", &xPos, &yPos);
        *((m + xPos*cols) + yPos) +=1;
    }
}

void print(int *m, int cols, int rows){
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", *((m+i*cols)+j));
        }
        printf("\n");
    }
}