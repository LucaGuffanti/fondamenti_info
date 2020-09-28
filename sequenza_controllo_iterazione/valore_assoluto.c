#include <stdio.h>

int main(){
  int numero;
  scanf("%d", &numero);
  if(numero < 0)
    numero = -numero;
  printf("%d\n", numero);
  return 0;
}