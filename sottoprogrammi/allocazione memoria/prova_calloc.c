#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 5, i;
    int *a;

    a = calloc(sizeof(int) * n, sizeof(int));
    if(a)
    for(i = 0; i < n; i++){
        printf("%d", *(a+i));
    }

    free(a);

    return 0;
}