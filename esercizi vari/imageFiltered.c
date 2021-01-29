#include <stdio.h>

void filtra(float [][], float [][], int, int, int, int);

void filtra(float image[][NC], float filtered[][NC], int nrow, int ncol, int frow, int fcol){
  float somma; 
  int i, j, k, h;

  for(i = 0, conta = frow*fcol; i < nrow; i++){
    for(j = 0; j < ncols; j++){
      for(k = -frow/2, somma = 0; k <= frow/2; k++){
        for(h = -fcol/2; h <= fcol/2; h++){
	  if(!((i+k < 0 || i+k >= nrow)||(j+h < 0 || j+h >= ncol)))
            somma+= image[i+k][j+h];
        }
      }
      filtered[i][j] = somma/conta;
    }
  }
}