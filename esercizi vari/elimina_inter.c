#include <stdio.h>

#define MAXS 50

void eliminaSegni(char*, char*);

int main(){

    char str[MAXS+1], s2[MAXS+1];
    scanf("%[^\n]", str);
    eliminaSegni(str, s2);

    printf("%s\n", s2);

    return 0;
}

void eliminaSegni(char* str, char *s2){
  int i, isSegno, k;

  for(i = 0, k = 0, isSegno = 0; str[k] != '\0'; i++){
      if(!((str[k] >= 'a' && str[k] <= 'z')||(str[k] >= 'A' && str[k] <= 'Z') || (str[k] >= '0' && str[k] <= '9') || str[k] == ' ')){
        printf("%c e' un segno\n", str[k]);
        isSegno = 1;
        k++;
      }else{
        s2[i] = str[k];
        k++;
      }
    }
  s2[i] = '\0';
}