#include <stdio.h>

int contaDistinti(char*, int);

int contaDistinti(char fn, int n){
  FILE* fp;
  char c;
  char str[n+1];
  int i, found, prevI;  

  fp = fopen(fn, "r");
  if(fp){
    i = 0;
    fscanf(fp, "%c", &c);
    while(!feof(fp) && i < n){
      prevI = i;
      for(found = 0; i >= 0 && !found; i--)
        if(str[i] == c)
          found = 1;
      
      i = prevI;
      if(!found){
       str[i] = c;
       printf("%c", c);  
      }
      i++;
      fscanf(fp, "%c", &c);
    }
    fclose(fp);  
  }else{
    printf("Errore di apertura del file\n");
  }
}