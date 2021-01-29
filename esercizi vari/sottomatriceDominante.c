#include<stdio.h>

int mDominante(int [][NC], int, int);

int mDominante(int m[][NC], int nr, int nc){
 int i, j, k, h;
 int esito;
 int num;
 int contaDom;
 
 contaDom = 0;
 for(i = 0; i < nr-1; i++){
   for(j = 0; j < nc-1; j++){
     num = m[i][j];
     for(k = i+1, esito = 0; k < nr && !esito; k++){
       for(h = j+1; h < nc && !esito; h++){
         if(m[k][h] > num)
           esito = 1;
       }
     }
     if(esito)
       contaDom++;
   }
 }
 return contaDom;
}