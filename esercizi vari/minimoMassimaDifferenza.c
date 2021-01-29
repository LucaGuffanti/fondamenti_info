int indiceColonna(int [][], int, int);
 
int indiceColonna(int m[][NC], int nrow, int ncol){
  int diff; 
  int minmaxdiff;
  int indexColminMax;
  int maxdiff;
  int i, j, h, k;
  int DefMinDiff;

  DefMinDiff = 0;
  for(i = 0; i < ncol; i++){
    for(j = 0, diff = 0, maxdiff = 0; j < nrow; i++){
      diff = m[j][i];
      for(k = j+1; k < nrow; k++){
        diff = diff - m[k][i];
        if(diff > maxdiff){
          maxdiff = diff;
          diff = m[j][i];
        }
      }
      if(maxdiff < minmaxdiff){
        minmaxdiff = maxdiff;
        indexColminMax = j;
        if(!DefMinDiff){
          minmaxdiff = minmaxdiff;
          indexColminMax = j;
        }
      }
    }
  }
  return indexColminMax;
}