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