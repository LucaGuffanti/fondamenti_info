#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i, n;

    /*
    sempre controllare che gli argomenti siano corretti
    perché in caso di errori non devo far crashare il programma
    */

    if(argc == 3){ /*nome dell'eseguibile, numero e stringa*/
        n = atoi(argv[1]);

        for(i = 0; i < n; i++){
            printf("%s\n", argv[2]);
        }
    
    }else{
        printf("Numero di argomenti non corretto\n");
    }

    return 0;
}