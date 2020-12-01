#include <stdio.h>

int somma(int, int);

int main(){
    int a, b, s;
    scanf("%d %d", &a, &b);
    s = somma(a, b);

    printf("%d\n", s);

    return 0;
}

int somma(int a, int b){
    int s_ = a + b;
    return s_;
}