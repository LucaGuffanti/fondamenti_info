#include <stdio.h>
#include <string.h>
#define MAXDIM 30

int main(){
    char str[MAXDIM+1];
    char filtro[MAXDIM+1] = {'t', 'e', 's', 't', '\0'};
    int i, equal;
    FILE* fp;
    if(fp = fopen("prova.txt", "r")){
       /*normalizzo il filtro*/
       for(i = 0; filtro[i] != '\0'; i++){
           if(filtro[i] >= 'A' && filtro[i] <= 'Z')
                filtro[i] = filtro[i] - 'A'+'a';
       }
       
       fscanf(fp, "%s", str);
       while(!feof(fp)){
        /*per ogni iterazione, normalizzo la stringa*/   
        for(i = 0; str[i]!='\0'; i++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';
        }
        /*e confronto con il filtro*/
        /*se sono uguali lo salto*/
        if(strcmp(str, filtro))
            printf("%s\n", str);
        fscanf(fp, "%s", str);
       }
    }else{
        printf("errore\n");
    }

    return 0;
}