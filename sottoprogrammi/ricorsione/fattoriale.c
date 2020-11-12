#include <stdio.h>

int fattoriale(int);

int main(){

    printf("%d\n", fattoriale(6));
    
    return 0;
}

int fattoriale(int n){
    if(n == 0 || n == 1)
        return 1;
    else
        return n * fattoriale(n - 1);
}