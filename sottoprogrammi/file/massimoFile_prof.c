#include <stdio.h>

#define FILENAME "TEST.txt"

int main(){
    FILE* fp;
    int n, max, conta;

    fp = fopen(FILENAME, "r");

    if(fp){

        fscanf(fp, "%d", &n);
        max = n;
        conta = 1;
        if(!feof(fp)){
            if(n > max){
                max = n;
                conta = 1;
            }
            else if(n == max){
                conta++;
            }

            fscanf(fp, "%d", &n);
        }

        printf("%d compare %d volte\n", max, conta);

        fclose(fp);

    }else{
        printf("Error\n");
    }

}