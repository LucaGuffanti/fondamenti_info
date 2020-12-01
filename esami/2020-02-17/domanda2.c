#include <stdio.h>
#include <string.h>

#define DIM 200


void trovaSottostringaNumerica(char [], int *, int *);

void trovaSottostringaNumerica(char str[], int *maxLen, int *minLen){

    int i, len, isNumber;

    *maxLen = 0; 
    *minLen = strlen(str);
    for(i = 0, len = 0, isNumber = 0; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            isNumber = 1;
            len++;
        }else{
            if(isNumber){
                if(len > *maxLen){
                    *maxLen = len;
                }
                if(len < *minLen){
                    *minLen = len;
                }
                len = 0;
                isNumber = 0;
            }
        }
    }
    /*questo devo metterlo perché potrei uscire dal ciclo ma avere comunque alla fine una sequenza di numeri*/
    if(isNumber){
        if(len > *maxLen){
            *maxLen = len;
        }
        if(len < *minLen){
            *minLen = len;
        }
        len = 0;
        isNumber = 0;
    }
}

int main(){
    char str[DIM+1];
    int maxLen, minLen;

    scanf("%s", str);
    trovaSottostringaNumerica(str, &maxLen, &minLen);

    printf("%d %d\n", maxLen, minLen);

    return 0;
}