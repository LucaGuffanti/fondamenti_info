/*
ES1. Scrivere un programma C che apre un file di testo "testo.txt" contenente parole ciascuna di al massimo 15 caratteri, separate da
spazi. Il programma trova tutte le parole più lunghe di 4 caratteri e ripetute due volte di seguito nel testo e le stampa a video. Gestire
opportunamente tutti gli eventuali errori.
Ad esempio, se il file "testo.txt" contiene il testo:
bisogna studiare passo passo e adagio adagio per ottenere un voto alto alto
Il programma visualizzerà in output:
passo adagio
*/

#include <stdio.h>
#include <string.h>

#define FILENAME "testo3.txt"
#define MAXLEN 15
#define MINLEN 4

int main(){

    FILE* fp;
    int i, fineparola;
    char str[MAXLEN+1], str2[MAXLEN+1];

    fp = fopen(FILENAME, "r");
    if(fp){
        fineparola = 0;
        i = 0;
        fscanf(fp, "%s", str);
        if(!feof(fp)){
            strcpy(str2, str);
            fscanf(fp, "%s", str);
            
            while(!feof(fp)){
                if(!strcmp(str2, str) && strlen(str) > 4)
                    printf("%s\n", str);
                strcpy(str2, str);
                fscanf(fp, "%s", str);
            }
        }
        fclose(fp);
    }else{
        printf("Errore nell'apertura del file\n");
    }

    return 0;
}