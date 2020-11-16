/*COME FILE IN INGRESSO INSERIRE successione.txt*/

#include <stdio.h>

#define STRDIM 30

int main(){

    FILE *fp;
    char filename[STRDIM + 1];
    int nCurr, nSucc;

    scanf("%s", filename);

    fp = fopen(filename, "r");

    if(fp){
        
        fscanf(fp, "%d", &nCurr);

        if(!feof(fp))
            fscanf(fp, "%d", &nSucc);

        while(!feof(fp)){

            if(nSucc == 2 * nCurr){
                printf("%d %d\n", nCurr, nSucc);
            }
            nCurr = nSucc;
            fscanf(fp, "%d", &nSucc);
        }

        

        fclose(fp);

    }else{
        printf("Error: file not opened");
    }
    
    return 0;
}