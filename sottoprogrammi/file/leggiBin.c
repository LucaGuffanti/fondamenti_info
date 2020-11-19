#include <stdio.h>

#define FN "ciao.bin"

int main(){
    /*LETTURA DI DIMENSIONE INDEFINITA*/
    FILE *fp;
    int n;

    fp = fopen(FN, "rb"); /*read binary*/

    if(fp){

        fread(&n, sizeof(int), 1, fp);

        while(!feof(fp)){
            printf("%d\n", n);
            fread(&n, sizeof(int), 1, fp);
        }
        
        fclose(fp);

    }else{
        printf("error\n");
    }


    return 0;
}

/*#include <stdio.h>
LETTURA DI DIMENSIONE FINITA
#define FN "ciao.bin"
#define DIM 10

int main(){

    FILE *fp;
    int a[DIM];
    int quanti_letti, i;

    fp = fopen(FN, "rb"); read binary

    if(fp){

        quanti_letti = fread(a, sizeof(int), DIM, fp);
        /*se io facessi quanti_letti = fread(a, sizeof(a), 1, fp);
        avrò come ritorno 1 o 0, il che mi indica quanti array di DIM elementi sono stati
        correttamente letti

        if(quanti_letti == DIM){
            for(i = 0; i < DIM; i++){
                printf("%d\n", a[i]);
            }
        }
        else{
            printf("errore");
        }
        fclose(fp);

    }else{
        printf("error\n");
    }


    return 0;
}*/