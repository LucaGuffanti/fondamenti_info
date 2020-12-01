#include <stdio.h>

#define FN "ciao.bin"
#define DIM 10

int main(){

    FILE *fp;
    int arr[DIM];
    int i;

    for(i = 0; i < DIM; i++){
        fscanf(stdin, "%d", &arr[i]);
    }

    fp = fopen(FN, "wb");

    if(fp){

        fwrite(arr, sizeof(int), DIM, fp);

        fclose(fp);

    }else{
        printf("error\n");
    }


    return 0;
}