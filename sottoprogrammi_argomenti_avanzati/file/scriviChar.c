/*Salviamo in modo permanente un'informazione*/

#include <stdio.h>

#define FILENAME "ciao.txt"

int main(){
    
    FILE* fp;
    char c;

    /*devo aprire il file in SCRITTURA*/
    /*fopen mi ritorna il puntatore al file nella tabella dei file aperti*/
    fp = fopen(FILENAME, "w");
    
    if(fp){
        
        for(c = '0'; c <= '9'; c++){
            fprintf(fp, "%c", c);
        }

        fclose(fp);

    }else{
        printf("Errore: File non aperto\n");
    }

    return 0;
}