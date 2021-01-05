#include <stdio.h>

#define DIM 10

int verificaScorrimento(int [], int [], int);

int main(){
 int v1[DIM], v2[DIM];
 int i;
 
 for(i = 0; i < DIM; i++)
   scanf("%d", &v1[i]);

 for(i = 0; i < DIM; i++)
   scanf("%d", &v2[i]);

 printf("%d verso destra\n", verificaScorrimento(v1, v2, DIM));

 return 0;
}

int verificaScorrimento(int v1[], int v2[], int dim){
  int v3[dim];
  int i;
  int scorrimento;
  int uguali;

  for(scorrimento = 0, uguali = 0; scorrimento < dim && !uguali; scorrimento++){
    for(i = 0; i < dim; i++)
      v3[(i+scorrimento)%dim] = v1[i];
    for(i = 0, uguali = 1; i < dim && uguali; i++)
      if(v3[i] != v2[i])
        uguali = 0;
  }
  scorrimento--;
  printf("Scorrimento:%d\nDimensione:%d\n", scorrimento, dim);
  if(uguali)
    return dim-scorrimento;
  else
    return -1;

}