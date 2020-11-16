#include <stdio.h>

#define MAXS 30

int main(){

    FILE *fp;
    char fn[MAXS + 1];
    int quanti, num, i;

    scanf("%s", fn);

    fp = fopen(fn, "w");

    if(fp){
        scanf("%d", &quanti);

        for(i = 0; i < quanti; i++){
            scanf("%d", &num);
            fprintf(fp, "%d ", num);
        }
        
        fclose(fp);
    }else{
        printf("Errore: file non aperto\n");
    }
    
    return 0;
}