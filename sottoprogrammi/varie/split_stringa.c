#include <stdio.h>
#include <string.h> 

#define TEXTL 150
#define WORDL 15
#define MAXWORD 12

void token(char [], char[][WORDL + 1], int, int*);

int main(){

    char line[TEXTL + 1];
    char tokens[MAXWORD][WORDL + 1];
    int i, j, wNum;

    scanf("%[^\n]", line);

    token(line, tokens, MAXWORD, &wNum);

    printf("%d\n", wNum);

    for(i = 0; i < wNum; i++){
        printf("%s\n", tokens[i]);
    }

    return 0;
}

void token(char line[], char tokens[][WORDL + 1], int wMax, int *wNum){

    int p, i;

    for(i = 0, p = 0, *wNum = 0; line[p] != '\0' && *wNum < wMax; p++){
        
        if(line[p] != ' '){
            /*salviamo lettera per lettera*/
            tokens[*wNum][i] = line[p];
            i++;

            if(i == WORDL){
                /*devo scartare la parola con la dimensione maggiore di quella*/
                while(line[p + 1] != '\0' && line[p + 1] != ' '){
                    p++;
                }
            }

        }else{
            /*dobbiamo disporre il conteggio di una nuova parola*/
            tokens[*wNum][i] = '\0';
            (*wNum)++;
            i = 0;
        }
    }

    if(p > 0 && (*wNum) < wMax){
        tokens[*wNum][i] = '\0';
        (*wNum)++;
    }

}
