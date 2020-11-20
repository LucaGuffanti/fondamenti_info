#include <stdio.h>

void isolaCifra(int, int);


int main(){

    int n;
    scanf("%d", &n);

    isolaCifra(n, n);

    return 0;
}

void isolaCifra(int num, int starting){
    if(starting == 0){
        printf("0");
        return;
    }
    if(num != 0){
        printf("%d", num%10);
        isolaCifra(num/10, starting);
    }
}