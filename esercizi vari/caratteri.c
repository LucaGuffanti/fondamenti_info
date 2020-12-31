#include <stdio.h>
#include <string.h>
#define MAXS 30

int main(int argc, char* argv[]){
    char str[30+1];
    int found, i, dimParola, len, lenFiltro, conta, j, k, isParola, endParola, h;
    char frase[250+1];
    char filtro[23+1];

    scanf("%[^\n]", frase);
    scanf(" %s", filtro);

    len = strlen(frase);
    lenFiltro = strlen(filtro);

    for(i = 0, k = 0, conta = 0, isParola = 0; frase[i]!= '\0'; i++){
        if(frase[i]!= ' ' && !isParola){
            isParola = 1;
        }
        if(isParola && !(frase[i] == ' ' || frase[i] == '\n')){
            str[k] = frase[i];
            k++;
        }
        if((frase[i] == ' ' || frase[i] == '\n') && isParola){
            isParola = 0;
            str[k] = '\0';
            found = 0;

            if(k != lenFiltro){
                found = 0;
            }else{
                for(j = 0, found = 1; str[j] != '\0' && found; j++){
                    if(filtro[j] != str[j]){
                        if(!(filtro[j] == (str[j] -'a'+'A') || filtro[j] == (str[j]-'A'+'a')))    
                            found = 0;
                    }
                }
            }

            k = 0;    
            if(found == 0){
                printf("%s ", str);
            }else{
                conta++;
            }
        }
    }
    /*questo perché potrei avere l'ultimo elemento di interesse*/
    if(isParola){
        str[k] = '\0';
        if(strlen(str) != lenFiltro){
            found = 0;
        }else{
            for(j = 0, found = 1; str[j] != '\0' && found; j++){
                if(filtro[j] != str[j]){
                    if(!(filtro[j] == (str[j] -'a'+'A') || filtro[j] == (str[j]-'A'+'a')))
                        found = 0;
                }
            }
        }
        k = 0;   
        if(found == 0){
            printf("%s ", str);
        }else{
            conta++;
        }
    }
    printf("\n");
    printf("%d\n", conta);
    return 0;

}