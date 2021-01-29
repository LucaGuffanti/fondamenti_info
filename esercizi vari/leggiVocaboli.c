#include <stdio.h>

void leggieTronca(char*, int);

void leggieTronca(char* fn, int n){
 FILE* fp;
 int i, isWord;
 char c;
 
 fp = fopen(fn, "r");
 if(fp){
  i = isWord = 0;
  fscanf(fp, "%c", &c);
  while(!feof(fp) && i < n){
   if(c != ' ' && !isWord){
    isWord = 1;
   }
   else if(c == ' ' && isWord){
    isWord = 0;
    i++;
   }
   fscanf(fp, "%c", &c);
  }
  if(i >= n){
   printf("...Continua a Leggere...\n");
  }
 }else{
  printf("Errore nell'apertura del file\n");
 }
 
}