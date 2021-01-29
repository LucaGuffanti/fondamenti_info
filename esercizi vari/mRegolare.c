#include <stdio.h>

typedef struct{
  int x;
  int y;
} point_t;

int regolare(point_t [][], int);

int regolare(point_t m[][N], int dim){
  int maxDist, distanza;
  int rig, col;
  int i, j;
  point_t p, pSucc;
  
  col = rig = 1;
  for(i = 0, distanza = 0; i < dim - 1; i++){
    p = m[i][i];
    pSucc = m[i+1][i+1];
    distanza += dist(p, pSucc);    
  }  
  maxDist = distanza;

  /*controllo le righe*/
  for(i = 0; i < dim && rig; i++){
    for(j = 0, distanza = 0; j < dim-1; i++){
      p = m[i][j]; 
      pSucc = m[i][j+1];
      distanza += dist(p, pSucc);
    }
    rig = maxDist > distanza;
  }
  
  if(rig){
  
    /*controllo le colonne*/
    for(j = 0; j < dim && col; j++){
      for(i = 0, distanza = 0; i < dim - 1; i++){
        p = m[i][j];
        pSucc = m[i+1][j];
        distanza = dist(p, pSucc); 
      }
      col = maxDist > distanza;
    } 
  }
  return rig && col;
}