#include <stdio.h>

int main(){
  int anno;
  scanf("%d", &anno);
  anno = (anno%4 == 0 && anno%100 != 0) || (anno%400 == 0);
  printf("%d\n", anno);
  return 0;
}