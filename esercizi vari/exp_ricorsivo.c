#include <stdio.h>

int esp(int , int );

int main(){
    int a,b;
    scanf("%d%d", &a, &b);

    printf("%d\n", esp(a, b));

    return 0;
}

int esp(int base, int exponent){
    if(exponent == 0)
        return 1;
    else
        return base * esp(base, exponent - 1);
}