#include <stdio.h>

#define FILENAME_R "testo.txt"
#define FILENAME_W "risultato.txt"
#define STRDIM 15

int analizza_stringa(char []);

int main(){

        FILE *fr_p;
        FILE *fw_p;
        char str[STRDIM + 1];
        
        fr_p = fopen(FILENAME_R, "r");
        fw_p = fopen(FILENAME_W, "w");

        if(fr_p && fw_p){

            fscanf(fr_p, "%s", str);
            
            while(!feof(fr_p)){
                if(analizza_stringa(str)){
                    fprintf(fw_p, "%s\n", str);
                }

                fscanf(fr_p, "%s", str);
            }

            fclose(fr_p);
            fclose(fw_p);

        }else{
            printf("Error: files not opened\n");
        }





    return 0;
}

int analizza_stringa(char str[]){
    
    int i;
    int lunghezza, nCifre, caratteri;
    int contaCaratteri, contaCifre;

    contaCaratteri = 0;
    contaCifre = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] >= '0' && str[i] <= '9')
            contaCifre++;
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
            contaCaratteri++;
        }
    }

    lunghezza = i > 5;
    nCifre = contaCifre >= 2;
    caratteri = nCifre && contaCaratteri >=1;

    return lunghezza && caratteri;

}