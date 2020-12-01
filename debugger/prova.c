#include <stdio.h>

void foo();

void foo(){
    int *a;
    *a = 20;
}

int main(){
    int i, n, s;
    foo();
    scanf("%d", &n);

    for(i = 0, s = 0; i < n; i++)
        s = s + i;

    printf("%d\n", s);
      
    return 0;
}
