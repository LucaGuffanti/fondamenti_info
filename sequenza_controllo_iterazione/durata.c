#include<stdio.h>
#define SEC_IN_MIN 60

int main(){
  int m, s;
  scanf("%d%d", &m, &s);
  m = m + s/SEC_IN_MIN;
  s = s % SEC_IN_MIN;
  printf("Durata: %d minuti, %d secondi\n", m, s);
  return 0;
} 