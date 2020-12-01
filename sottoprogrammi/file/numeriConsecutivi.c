#include <stdio.h>

int main(int argc, char* argv[]){
    int currLen, n1, n2, maxLen, maxElem;
    FILE *fp;

    if(argc == 2){

        fp = fopen(argv[1], "r");
        if(fp){

            currLen = 0;
            maxLen = 0;
            maxElem = 0;

            fscanf(fp, "%d", &n1);
            if(!feof){

                currLen = 1;
                maxLen = 1;
                maxElem = n1;
                fscanf(fp, "%d", &n2);

                while(!feof(fp)){
                    if(n2 == n1){
                        currLen++;
                    }else{
                        if(currLen >= maxLen){
                            maxLen = currLen;
                            maxElem = n1;
                        }
                        currLen = 1;   
                    }
                    n1 = n2;
                    fscanf(fp, "%d", &n2);
                }

                if(currLen >= maxLen){
                    maxLen = currLen;
                    maxElem = n1;
                }

                printf("valore: %d, lunghezza: %d\n", maxElem, maxLen);
            
            }else{
                printf("sequenza nulla\n");
            }

        fclose(fp);

        }else{
            printf("Errore di apertura del file\n");
        }
    }else{
        printf("Numero di argomenti scorretto\n");
    }

    return 0;
}