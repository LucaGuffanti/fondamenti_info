#include <stdio.h>
#define PI 3.1415

int main(){
  float r, p, a;
  scanf("%f", &r);
  p = 2 * PI * r;
  a = PI * r * r;
  printf("Perimetro: %f\nArea: %f\n", p, a);
  return 0;
}