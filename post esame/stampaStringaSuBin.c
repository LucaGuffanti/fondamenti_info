#include <stdio.h>
#include <string.h>

#define MAXS 30

typedef struct{
    int numero;
    char str1[MAXS+1];
    char str2[MAXS+1];
    float* floatp;
} prova_t;

int main(void){
    FILE* fp;
    prova_t p;
    
    fp = fopen("prova.bin", "wb");
    if(fp){
        p.numero = 100;
        strcpy(p.str1, "ciao\0");
        strcpy(p.str2, "mamma\0");
        fwrite(&p, sizeof(prova_t), 1, fp);
        
        fclose(fp);
        fp = fopen("prova.bin", "rb");
        if(fp){
            fread(&p, sizeof(prova_t), 1, fp);
            printf("%d\n%s\n%s\n%p\n",p.numero, p.str1, p.str2, p.floatp);
        }

    }


    return 0;
}   