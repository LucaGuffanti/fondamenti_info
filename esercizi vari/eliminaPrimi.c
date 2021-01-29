#include <stdio.h>
#include <stdlib.h>

nodo_t* eliminaPrimi(nodo_t*);
int isPrime(int);

nodo_t* eliminaPrimi(nodo_t* h){
 nodo_t* tmp;
 for(tmp = h; tmp; tmp = tmp->next){
   if(isPrime(tmp->n)
    h = delete(h, tmp->n);
 }
 return h;
}

int isPrime(int n){
  int primo;
  int i;

  for(i = 2, primo = 1; i*i <= n && primo; i++)
    if(n%i == 0)
     primo = 0;

  return primo;
}