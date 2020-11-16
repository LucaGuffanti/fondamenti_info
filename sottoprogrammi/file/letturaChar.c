#include <stdio.h>

#define FILENAME "ciao.txt"

int main(){

    FILE *fp;
    char c;

    fp = fopen(FILENAME, "r");

    if(fp){

        /*!!!unico modo per leggere un file di lunghezza indefinita!!!*/

        fscanf(fp, "%c", &c);

        while(!feof(fp)){
            printf("%c", c);
            fscanf(fp, "%c", &c);

        }

        fclose(fp);

    }else{
        printf("Errore\n");
    }
    return 0;
}