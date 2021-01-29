#include <stdio.h>

#define DIM 10

int verificaVetta(int[], int, int, int);
int calcolaNVette(int[], int, int);

int main(){
   int v[DIM] = {1, 9, 3, 8, 5, 6, 4, 7, 2, 0};
   int cont;

    cont = calcolaNVette(v, DIM, 0);
    printf("%d\n", cont);
    return 0;
    /*array fornito: 1 9 3 8 5 6 4 7 2 0. mi aspetto 3*/
}

int calcolaNVette(int v[], int dim, int indice){
    int esito;
    if(indice == dim-1)
      return 0;
    else{
      esito = verificaVetta(v, dim, indice+1, v[indice]);
      if(esito) printf("%d e' una vetta\n", v[indice]);
      return esito + calcolaNVette(v, dim, indice+1);
    }
}

int verificaVetta(int v[], int dim, int indice, int valore){
  if(indice == dim-1){
    return valore > v[indice];
  }
  else{
    return (valore > v[indice]) && verificaVetta(v, dim, indice+1, valore); 
  }

}