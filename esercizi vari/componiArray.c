#include <stdio.h>

#define DIM 10

int componiArray(int [], int, int);


int main(){
    int arr[] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    if(componiArray(arr, 10, DIM)){
        for(i = 0; i < DIM; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }else{
        printf("Non ho eseguito nessuna operazione\n");
    }
    return 0;
}

int componiArray(int arr[], int n, int dim){
    int isDivisore;
    int contaRipetizioni;
    int contaValori;
    int lunghezzaSottoparte;
    int i;
    /*dim = 10, n = 10
    0 0 0 0 0 0 0 0 0 0 
    10 9 8 7 6 5 4 3 2 1 
    
    */
    isDivisore = dim%n == 0;
    if(isDivisore){
      lunghezzaSottoparte = dim/n;
      contaRipetizioni = contaValori = 0;
      for(i = 0; i < dim; i++){
          if(contaValori != lunghezzaSottoparte){
            arr[i] = n - contaRipetizioni;
            contaValori++;
          }
          if(contaValori == lunghezzaSottoparte){
              contaValori = 0;
              contaRipetizioni += 1;
          }
      }
    }
    return isDivisore;
}