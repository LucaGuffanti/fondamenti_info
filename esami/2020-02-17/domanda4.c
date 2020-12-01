#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *fp;
    int n1, n2, n3, somma, sequenza;

    if(argc == 2){

        fp = fopen(argv[1], "r");
        if(fp){

            sequenza = 1;
            fscanf(fp, "%d", &n1);
            if(!feof(fp) && n1 == 0){

                fscanf(fp, "%d", &n2);

                if(!feof(fp) && n2 == 1){
                
                    fscanf(fp, "%d", &n3);
                
                    while(!feof(fp) && sequenza){
                
                        sequenza = (n1+n2) == n3;
                
                        if(sequenza){
                
                            n1 = n2;
                            n2 = n3;
                            fscanf(fp, "%d", &n3);
                        }
                    }
                }else{
                    sequenza = 0;
                }
            }else{
                sequenza = 0;
            }
            printf("%d\n", sequenza);
            fclose(fp);
        }else{
            printf("Errore nell'apertura\n");
        }
    }else{
        printf("Argomenti errati\n");
    }

    return 0;
}