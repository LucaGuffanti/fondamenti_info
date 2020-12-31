#include <stdio.h>

#define DIM 3

void load(int *, int, int);

void print(int *, int, int);


int main(){
    int m[DIM][DIM];

    load(&m[0][0], DIM, DIM);
    print(&m[0][0], DIM, DIM);

    return 0;
}

void load(int *m, int col, int row){
    int i, j;
    int *cellIndex;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            cellIndex = (m + i*col) + j;
            scanf("%d", cellIndex);
        }
    }
}
void print(int *m, int col, int row){
    int i, j;
    int *cellIndex;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            cellIndex = (m + i*col) + j;
            printf("%d ", *cellIndex);
        }
        printf("\n");
    }

}