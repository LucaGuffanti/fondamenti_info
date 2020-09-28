#include <stdio.h>

int main(){
  int n1, n2, max;
  scanf("%d%d", &n1, &n2);
  
  if(n1 > n2)
  	max = n1;
  else if (n2 > n1)
  	max = n2;
  else
  	max = 0;

  printf("%d\n", max);
  return 0;
}