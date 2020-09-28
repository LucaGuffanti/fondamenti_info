#include <stdio.h>

int main(){
  float gradi_F, gradi_C;
  scanf("%f", &gradi_C);
  gradi_F = (gradi_C * 1.8) + 32;
  printf("Gradi Farenheit: %f\n", gradi_F);
  return 0;
}