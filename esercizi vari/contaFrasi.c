#include <stdio.h>

#define MAXS 200
#define DIMFN 80

int main(int argc, char* argv[]){
  char fn[DIMFN+1];
  char c;
  FILE* fp;  
  int i, maxN, minN, n, cRighe, cFrasi; 
  
  scanf("%s", fn);
  fp = fopen(fn, "r");
  if(fp){
    maxN = n = cRighe = cFrasi = 0;
    minN = DIMFN;

    fscanf(fp, "%c", &c);
    while(!feof(fp)){
      if(c == '.'){
        cFrasi++;
        if(n > maxN)
          maxN = n;
        else if(n < minN)
          minN = n;

        n = 0;  
      }
      else if(c == '\n'){
        cRighe++;
      }
      else if(c != ' '){
        n++;
      }
      fscanf(fp, "%c", &c);
    }
    printf("Max: %d\nMin: %d\nRighe: %d\nFrasi: %d\n", maxN, minN, cRighe, cFrasi);
    fclose(fp);
  }else{
    printf("Errore nell'apertura del file\n");
  }

 return 0;
}