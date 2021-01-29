void visualizzaElementiMatrice(int [][NC], int, int, int);

void visualizzaElementiMatrice(int m[][NC], int nrig, int ncol, int i){
 int j;
  for(j = 0; j < nrig; j++){
    if(m[j][i] == 1)
     printf("%d\n", m[j][i]);
  }
  for(j = 0; j < ncol; j++){
    if(m[i][j] == 0)
      printf("%d\n", m[i][j]);
  }
}