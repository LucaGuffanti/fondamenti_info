#include <stdio.h>
#include <string.h>

#define NSTUDENTI 100
#define DIMNOME 20

typedef struct{
    char voto;
    char nome[DIMNOME + 1];

} studente_t;

int main(){
    studente_t arr[NSTUDENTI], max;
    int quanti, i;
    int vMax;

    printf("Inserire il numero di studenti:\n");
    scanf("%d", &quanti);

    for(i = 0; i < quanti; i++){
        scanf("%[^\n]", arr[i].nome);
        scanf(" %c", &arr[i].voto);
    }

    max = arr[0];

    for(i = 1; i < quanti; i++){
        if(arr[i].voto > max.voto){
            max.voto = arr[i].voto;
            strcpy(max.nome, arr[i].nome);
        }
    }

    printf("%s\n -> %d", max.nome, max.voto);



    return 0;
}