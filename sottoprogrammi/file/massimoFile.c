#include <stdio.h>

#define FILENAME "TEST.txt"

int main(){

    FILE *file;
    int n, max;
    int i;

    file = fopen(FILENAME, "r");

    if(file){

        fscanf(file, "%d", &n);
        max = n;
        i = 0;

        while(!feof(file)){
            i++;
            if(n > max){
                max = n;
            }
            fscanf(file, "%d", &n);
        }

        if(i)
            printf("%d e' il valore massimo nel file.\n", max);
        else
            printf("File di dimensione nulla");

        fclose(file);
    }else{
        printf("Error: file not opened\n");
    }


    return 0;
}