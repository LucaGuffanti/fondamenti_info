#include <stdio.h>

#define N 10

int check_array(int [], int [], int);


int main(){

    int a[N], b[N];
    int i, ris;

    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < N; i++){
        scanf("%d", &b[i]);
    }

    ris = check_array(a, b, N);

    printf("%d\n", ris);

    return 0;
}

int check_array(int a[], int b[], int dim){
    int i, j, ok, found;

    for(i = 0, found = 0; i < dim && !found; i++){
        for(j = 0, ok = 1; j < dim && ok; j++){
            
            if(a[j] != b[(i + j)%dim]){
                ok = 0;
            }
        }
        if(ok){
            found = 1;
        }
    }
    if(found){
        i--;
    }
    if(!found){
        i = -1;
    }
    return i;
}