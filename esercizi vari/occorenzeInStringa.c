#include <stdio.h>
#include <string.h> 

int* conta(char*, char);

int main(int argc, char* argv[]){
  int* occ;
  int i;
  
  if(argc == 3){
    occ = conta(argv[1], argv[2]);
    for(i = 0; argv[2] != '\0'; i++)
      printf("%c %d\n", argv[2][i], occ[i]);
  }else{
    print("Errore negli argomenti");
  }

  return 0;
}

int* conta(char* info, char* cars){
  int* occorrenze;
  int len;
  int i, j;
 
  len = strlen(cars);
  occorrenze = malloc(sizeof(int)*len);
  if(occorrenze){
    for(i = 0; i < len; i++)
      occorrenze[i] = 0;


    for(i = 0; i < len; i++){
      for(j = 0; info[j] != '\0'; j++){
        if(info[j] == cars[i])
          occorrenze[i]++;
      }
    }
  }else{
    printf("Errore nell'allocazione\n");
  }

  return occorrenze;
}