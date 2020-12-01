#include <stdio.h>

#define FN "ciao.bin"

int main(){

    FILE *fp;
    int n, i, v;

    fp = fopen(FN, "wb");

    if(fp){
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d", &v);
            fwrite(&v, sizeof(int), 1, fp); /*sizeof(tipo) mi dice quanti byte occupa un tipo*/
        }

        fclose(fp);

    }else{
        printf("error\n");
    }


    return 0;
}