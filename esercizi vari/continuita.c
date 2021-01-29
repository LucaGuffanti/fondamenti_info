#include <stdio.h>

int verificaContinuita(int [], int, int);

int verificaContinuita(int v[], int da, int a){
  int esito;
  int i, j;
  int tmp;
  

  len = a - da + 1;
  for(i = 0; i < len; i++)
     for(j = i+1; j < len; j++){
       if(v[i] < v[j]){
         tmp = v[i];
         v[i] = v[j];
         v[j] = tmp;
       }
     } 
   for(i = 0, esito = 1; i < len && esito; i++){
     if(v[i] != da+i)
       esito = 0;
   }

   retrun esito;
}