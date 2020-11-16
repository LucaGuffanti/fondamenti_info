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
        /*è bene analizzare questa porzione di codice*/
        /*la presenza di un separatore alla fine mi evita di riconoscere erroneamente
        l'ultimo numero come una lettura di un carattere irregolare, impedendo
        l'omissione dell'ultimo numero */

        /*quindi quando scrivo un file devo sempre inserire i separatori, per essere 
        certo di non avere errori successivamente*/
        while(!feof(fp)){
            printf("%d", n);
            fscanf(fp, "%d", &n);
        }

        printf("\n");

        fclose(fp); 
        /*come posso ovviare a questo problema?
        
        int ris;
        ..
        ris = fscanf(fp, "%d", &n); noto che -1 indica che non c'è staa alcuna lettura
        while(ris > 0){
            printf("%d\n", n);
            ris = fscanf(fp, "%d", &n);
        }
        
        */
    }else{
        printf("Errore: file non aperto\n");
    }

    return 0;
}