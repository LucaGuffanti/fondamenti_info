#include <stdio.h>

#define MAXS 30

int main(){

    FILE *fp;
    char fn[MAXS + 1];
    int n;

    scanf("%s", fn);

    fp = fopen(fn, "r");

    if(fp){
        
        fscanf(fp, "%d", &n);

        while(!feof(fp)){
            printf("%d", n);
            fscanf(fp, "%d", &n);
        }

        printf("\n");

        fclose(fp); 

    }else{
        printf("Errore: file non aperto\n");
    }

    return 0;
}