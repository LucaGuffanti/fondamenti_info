#include <stdio.h>
#define BANCONOTA_50 50
#define BANCONOTA_20 20
#define BANCONOTA_10 10
#define BANCONOTA_5 5

int main(){
  int n_50, n_20, n_10, n_5;
  int totale;
  scanf("%d%d%d%d", &n_50, &n_20, &n_10, &n_5);
  totale = (n_50 * BANCONOTA_50) + (n_20 * BANCONOTA_20) + (n_10 * BANCONOTA_10) + (n_5 * BANCONOTA_5);
  printf("Il totale dei soldi e': %d\n", totale);
  return 0;
}