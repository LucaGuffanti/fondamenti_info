/*
58. Write a program in C to move all zeroes to the end of a given array.
Expected Output :
The given array is : 2 5 7 0 4 0 7 -5 8 0
The new array is:
2 5 7 8 4 -5 7 0 0 0
*/

#include <stdio.h>
#include <stdlib.h>

void spostaZeri(int *, int);
void salvaSuFile(int *, int);

int main(){
    int *arr;
    int len;
    int i;

    scanf("%d", &len);
    if(arr = (int *)malloc(sizeof(int) * len)){
        for(i = 0; i < len; i++){
            scanf("%d", &arr[i]);
        }
        spostaZeri(arr, len);
        salvaSuFile(arr, len);
        free(arr);
    }else{
        fprintf(stderr, "Errore\n");
    }
    return 0;
}

void spostaZeri(int *arr, int len){
    int i;
    int tmp;
    for(i = 0; i < len/2; i++){
        if(arr[i] == 0){
            tmp = arr[i];
            arr[i] = arr[len - i - 1];
            arr[len - i - 1] = tmp;
        }
    }
    return;
}

void salvaSuFile(int *arr, int len){
    const char* nomeFile = "result.txt";
    FILE *fp;
    int i;

    fp = fopen(nomeFile, "w");
    if(fp){
        for(i = 0; i < len; i++){
            fprintf(fp, "%d ", arr[i]);
        }
    }else{
        fprintf(stderr, "Errore\n");
    }
}