#include <stdio.h>
#include <math.h>

#define N 3 

typedef struct{

    int x;
    int y;

} point_t;

float distanza(point_t, point_t);

int regolare(point_t [][N], int);

int main(){

    point_t punti[N][N];
    int i, j;
    int flag;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d%d", &punti[i][j].x, &punti[i][j].y);
        }
    }

    flag = regolare(punti, N);

    printf("%d\n", flag);

    
    return 0;
}



float distanza(point_t p1, point_t p2){

    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int regolare(point_t matrice[][N], int dim){
    
    float dist_diag;
    float dist_rc;
    int i, j, flag;

    /*calcolo la distanza della spezzata sulla diagonale*/
    for(i = 0, dist_diag = 0; i < dim - 1; i++){
        dist_diag += distanza(matrice[i][i], matrice[i + 1][i + 1]);
    }

    for(i = 0, flag = 1; i < dim && flag; i++){
        for(j = 0, dist_rc = 0; j < dim - 1; j++){
            dist_rc += distanza(matrice[i][j], matrice[i][j+1]);
        }

        if(dist_rc > dist_diag){
            flag = 0;
        }
    }

    for(j = 0; j < dim && flag; j++){
        for(i = 0; i < dim-1; i++){
            dist_rc += distanza(matrice[i][j], matrice[i+1][j]);
        }

        if(dist_rc > dist_diag){
            flag = 0;
        }
    }

    return flag;

}