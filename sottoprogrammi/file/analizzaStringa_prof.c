#include <stdio.h>

#define FILENAMEIN "testo.txt"
#define FILENAMEOUT "risultato.txt"
#define MAXS 15

int analizzaStringa(char []);

int main(){

    FILE *fpi;
    FILE *fpo;
    char str[MAXS + 1];

    fpi = fopen(FILENAMEIN, "r");
    
    if(fpi){
       
        fpo = fopen(FILENAMEOUT, "w");

        if(fpo){

            fscanf(fpi, "%s", str);

            while(!feof(fpi)){
                
                if(analizzaStringa(str)){
                    fprintf(fpo, "%s\n", str);
                }

                fscanf(fpi, "%s", str);
            }

            fclose(fpo);
        }else{
            printf("Error\n");
        }

        fclose(fpi);
        
    }else{
        printf("Error\n");
    }

    return 0;
}

int analizzaStringa(char str[]){

    int numCifre, len;
    
    for(numCifre = 0, len = 0; str[len] != '\0'; len++){
        
        if(str[len] >= '0' && str[len] <= '9'){
            numCifre++;
        }
    }

    return numCifre >= 2 && len > numCifre && len >= 5;
}