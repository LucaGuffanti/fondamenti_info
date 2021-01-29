#include <stdio.h>

void genera(char*, int);

int main(int argc, char* argv[]){
 if(argc == 2)
  genera(argv[1], 0);
 else
  printf("Errore\n");
 return 0;
}

void genera(char* str, int indice){ 
   if(str[indice] == '\0'){
     printf("%s\n\n", str);
     return;
    }
    else if(str[indice] == 'x'){
      str[indice] = '0';
      genera(str, indice+1);
      str[indice] = '1';
      genera(str, indice+1);
      str[indice] = 'x';
    }else{
      genera(str, indice+1);
    }
    return;
}


