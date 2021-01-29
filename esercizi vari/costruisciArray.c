#include <stdio.h>

void costruisciArray(int, char*, int, int);

void costruisciArray(int n, char* s, int i, int dim){
  int j;
  for(j = dim-1; j >= i; j--){
    s[j] = n%10 + '0';
    n = n%10;
  }
}