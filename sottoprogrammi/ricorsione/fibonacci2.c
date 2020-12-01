#include <stdio.h>

int fibonacci(int);

int main(){

    int n;
    scanf("%d", &n);

    printf("%d", fibonacci(n));

    return 0;
}

int fibonacci(int n){
    if(n == 0 || n == 1){
    
        return 1;
    }
    else{
        printf("%d\n", fibonacci(n-1) + fibonacci(n-2));
        return fibonacci(n-1) + fibonacci(n-2);
    }
}