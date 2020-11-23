#include <stdio.h>
#include <string.h>

#define DIM 5

void writeBinary(FILE *, char [], int [], int);
void loadBinary(FILE *, char [], int [], int);

int main(){
    FILE *fp;
    char filename[DIM + 1];
    int content[DIM];
    int i;

    scanf("%s", filename);

    for(i = 0; i < DIM; i++){
        scanf("%d", &content[i]);
    }

    writeBinary(fp, filename, content, DIM);
    
    for(i = 0; i < DIM; i++){
        content[i] = 0;
    }

    loadBinary(fp, filename, content, DIM);

    for(i = 0; i < DIM; i++){
        printf("%d\n", content[i]);
    }

    return 0;
}

void writeBinary(FILE *fp, char fn[], int str[], int dim){

    fp = fopen(fn, "wb");
    
    if(fp){

        fwrite(str, sizeof(int), dim, fp);

        fclose(fp);

    }else{
        printf("Error opening in writing\n");
    }

}

void loadBinary(FILE *fp, char fn[], int str[], int dim){
    
    int correctRead;
    int i;

    fp = fopen(fn, "rb");

    if(fp){

        correctRead = fread(str, sizeof(int), dim, fp);

        if(correctRead){
            printf("read successful\n");
        }
        
        fclose(fp);

    }else{
        printf("Error opening in reading\n");
    }

}