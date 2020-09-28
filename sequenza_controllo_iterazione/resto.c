#include <stdio.h>

int main(){
  int soldi, resto_5, resto_1;
  scanf("%d", &soldi);
  resto_5 = soldi / 5;
  resto_1 = soldi % 5;
  printf("%d banconote da 5 euro\n%d monete da 1 euro\n", resto_5, resto_1);
  return 0;
}