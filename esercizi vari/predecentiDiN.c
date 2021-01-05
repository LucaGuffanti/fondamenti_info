#include <stdio.h>

int contaPrecedentiDiN(nodo_t*, int);
int contaPrecedentiDiN(nodo_t* h, int n){
  if(h->num == n)
    return 0;
  else
    return 1 + contaPrecedentiDiN(h->next, n); 
}