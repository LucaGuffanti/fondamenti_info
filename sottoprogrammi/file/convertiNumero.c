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
    int strIndex, neg, digit;

    for(strIndex = 0, *num = 0, *valido = 1, neg = 0; str[strIndex] != '\0' && valido; strIndex++){
        
        if(str[strIndex] >= '0' && str[strIndex] <= '9'){
            switch(str[strIndex]){
                case '0':
                    digit = 0;
                    break;
                case '1':
                    digit = 1;
                    break;
                case '2':
                    digit = 2;
                    break;
                case '3':
                    digit = 3;
                    break;
                case '4':
                    digit = 4;
                    break;
                case '5':
                    digit = 5;
                    break;
                case '6':
                    digit = 6;
                    break;
                case '7':
                    digit = 7;
                    break;
                case '8':
                    digit = 8;
                    break;
                case '9':
                    digit = 9;
                    break;
                default:
                    digit = 0;
                    break;
            };
            *num = (*num * BASE_CONVERSIONE) + digit;
        }
        else if(str[strIndex] == '-'){
            neg = !neg;
        }
        else{
            valido = 0;
        }
    }

    if(neg){
        *num = -(*num);
    }
    if(!valido){
        *num = 0;
    }
}