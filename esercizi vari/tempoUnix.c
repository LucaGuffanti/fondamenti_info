#include <stdio.h>

void visualizzaDistanzaUnix(int, int);

void visualizzaDistanzaUnix(int da, int a){
  int diff;
  int gg, hr, min, sec;
  
  diff = a - da;
  
  gg = diff/86400;
  diff = diff%86400;
  hr = diff/3600;
  diff = diff%3600;
  min = diff/60;
  sec = sec%60;
  
  printf("%d giorni %d ore %d minuti %d secondi\n", gg, hr, min, sec);
}


18000 secondi
18000 % 60 = 0 secondi
300 minuti % 60 = 0 minuti x ore
5 