/*esercizio del conteggio in modo ricorsivo*/

#include <stdio.h>
#include <stdlib.h>

void conta(int, int);
void conta_ric(int, int, int*, int);

int main(){
    int n, b;
    scanf("%d%d", &n, &b);
    conta(n, b);

    return 0;
}

void conta(int n, int b){
    int *num;

    num = malloc(sizeof(int) * n);
    if(num){
        conta_ric(n, b, num, 0);
        free(num);
    }else{
        printf("Errore nell'allocazione\n");
    }
}

void conta_ric(int n, int b, int* num, int curr_n){
    int i;
    if(curr_n == n){
        for(i = 0; i < n; i++)
            printf("%d", num[i]);
        printf("\n");
    }else{
        for(i = 0; i < b; i++){
            num[curr_n] = i;
            conta_ric(n, b, num, curr_n+1);
        }
    }
}