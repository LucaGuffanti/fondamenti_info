#include <stdio.h>

#define FILENAME "testo.txt"
#define SDIM 15


void convertiNumero(char [], int *, int *);

int main(){
    
    FILE *fp;
    char str[SDIM + 1];
    int somma, n, valido;

    fp = fopen(FILENAME, "r");

    if(fp){
        
        somma = 0;

        fscanf(fp, "%s", str);

        while(!feof(fp)){
            
            convertiNumero(str, &n , &valido);
            
            if(valido){
                somma += n;
            }

            fscanf(fp, "%s", str);
        }

        printf("%d\n", somma);

        fclose(fp);

    }else{
        printf("Error: flie not opened\n");
    }

    return 0;
}

void convertiNumero(char str[], int *ris, int *valido){
    
    int i, pot10;
    
    *valido = 1;

    for(i = 0; str[i] != '\0'; i++);

    for(i--, *valido = 1, *ris = 0, pot10 = 1; i >= 0 && *valido; i--, pot10 *= 10){
        
        if(str[i] >= '0' && str[i] <= '9') {
            *ris = *ris + pot10 * (str[i] - '0');
        }else{
            *valido = 0;
        }
    }
}