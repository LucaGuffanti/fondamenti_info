#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    char* str;
    char* str2;
    int i, j;

    int len;
    len = strlen(argv[1]);
    str = malloc(sizeof(char)*(len+1));
    str2 = malloc(sizeof(char)*(len+1));
    printf("%s\n", argv[1]);
    strcpy(str, argv[1]);
    for(i = 0, j = 0; str[i] != '\0'; i++){
        if(str[i] != 'a'){
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = '\0';
    printf("%s\n", str2);
    strcpy(str, str2);
    printf("%s\n", str);
    return 0;
}