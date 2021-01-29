#include <stdio.h>

int main(){
   char str[200+1];
   scanf("%[^.]", str);
   printf("%s\n", str);
   return 0;
}