#include <stdio.h>

#define BASE_CONVERSIONE 10
#define STRDIM 15
#define FILENAME "testo.txt"

void converti_numero(char [], int *, int *);

int main(){

    FILE *fp;
    int i, somma, valido, num;
    char str[STRDIM + 1];

    fp = fopen(FILENAME, "r");
    
    if(fp){
        
        fscanf(fp, "%s", str);
        somma = 0;
        while(!feof(fp)){

            converti_numero(str, &num, &valido);

            if(valido){
                somma += num;
            }

            fscanf(fp, "%s", str);
        }

        printf("Somma: %d", somma);

        fclose(fp);

    }else{
        printf("Error: file not opened\n");
    }

    return 0;
}

void converti_numero(char str[], int *num, int *valido){
    int strIndex;

    for(strIndex = 0, *num = 0, *valido = 1; str[strIndex] != '\0' && valido; strIndex++){
        
        if(str[strIndex] >= '0' && str[strIndex] <= '9'){
            *num = (*num * BASE_CONVERSIONE) + str[strIndex] - '0';
        }
        else{
            valido = 0;
        }
    }
    
    if(!valido){
        *num = 0;
    }
}