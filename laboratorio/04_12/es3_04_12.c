/*
Definire un tipo di dato per una lista dinamica di parole, dove
ciascuna parola è lunga al massimo 20 caratteri. Realizzare i
sottoprogrammi standard per la gestione di una lista di parole, in
particolare per l'inserimento in coda di un nuovo elemento, la
visualizzazione del contenuto della lista, il calcolo della
lunghezza della lista e la sua distruzione.
Scrivere un programma che riceve come argomenti i nomi di due file
di testo, ciascuno contenente una sequenza di lunghezza indefinita
di parole di al massimo 20 caratteri. Il programma carica le due
sequenze in due liste dinamiche s1 e s2. In seguito, il
sottoprogramma verifica se s1 è sottosequenza di s2 o, viceversa se
s2 è sottosequenza di s1, e stampa a video i risultati dei test (1 o
0); si noti che se almeno una delle due liste è vuota l'esito è
negativo. Prima di terminare il programma libera tutta la memoria
allocata. Visualizzare opportuni messaggi nel caso di errore (es:
argomenti mancanti, memoria non allocata correttamente, file non
aperto, ...). Si consiglia di suddividere opportunamento il
programma in sottoprogrammi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SDIM 20

typedef struct nodo_{
    char str[SDIM + 1];
    struct nodo_ *next;
} parola_t;

parola_t* inserireInCoda(parola_t*, char []);
int verificaSottosequenza(parola_t*, parola_t*);
int lunghezza(parola_t*);
parola_t* distruggi(parola_t*);
void visualizza(parola_t*);

int main(int argc, char *argv[]){
    parola_t *p1;
    parola_t *p2;
    FILE *fp1;
    FILE *fp2;
    char c;
    char s[SDIM + 1];
    int i;

    p1 = NULL;
    p2 = NULL;

    if(argc == 3){
        fp1 = fopen(argv[1], "r");
        if(fp1){
            fp2 = fopen(argv[2], "r");
            if(fp2){
                
                /*costruisco la prima lista*/
                i = 0;
                fscanf(fp1, "%c", &s[i]);

                while(!feof(fp1)){
                    if(s[i] == ' '){
                        s[i] = '\0';
                        i = 0;

                        p1 = inserireInCoda(p1, s);
                    }else{
                        i++;
                    }
                    fscanf(fp1, "%c", &s[i]);
                }
                if(i != 0){
                    s[i] = '\0';
                    p1 = inserireInCoda(p1, s);
                }
                /*costruisco la seconda lista*/

                i = 0;
                fscanf(fp2, "%c", &s[i]);

                while(!feof(fp2)){
                    if(s[i] == ' '){
                        s[i] = '\0';
                        i = 0;
                        
                        p2 = inserireInCoda(p2, s);
                    }else{
                        i++;
                    }
                    fscanf(fp2, "%c", &s[i]);
                }
                if(i != 0){
                    s[i] = '\0';
                    p2 = inserireInCoda(p2, s);
                }

                visualizza(p1);
                visualizza(p2);

                printf("%d\n", verificaSottosequenza(p1, p2));

                distruggi(p1);
                distruggi(p2);

            }else{
                printf("Errore nell'apertura\n");
            }
        }else{
            printf("Errore nell'apertura\n");
        }
    }else{
        printf("Argomenti scorretti\n");
    }

}

parola_t* inserireInCoda(parola_t *p, char s[]){
    
    parola_t *tmp;
    parola_t *curr;

    tmp = malloc(sizeof(parola_t));
    if(tmp){

        tmp->next = NULL;
        strcpy(tmp->str, s);
        if(p){
            for(curr = p; curr && curr->next; curr = curr->next);
            curr->next = tmp;
        }else{
            p = tmp;
        }
    }else{
        printf("Errore nell'allocazione\n");
    }

    return p;
}

int verificaSottosequenza(parola_t *p1, parola_t *p2){
    
    parola_t *tmp, *tmp2;
    int l1, l2;
    int ris;

    if(p1 && p2){
        printf("Calcolo la presenza di sottosequenze\n");
        l1 = lunghezza(p1);
        l2 = lunghezza(p2);
        /*assumo che sia p1 ad essere di dimensione maggiore*/
        if(l1 < l2){
            printf("Noto che p2 ha dimensione maggiore di p1, le scambio\n");
            tmp = p1;
            p1 = p2;
            p2 = tmp;
        } 

        for(ris = 0; p1 && !ris; p1 = p1->next){
            for(tmp2 = p2, tmp = p1; tmp2 && tmp; tmp2 = tmp2->next, tmp = tmp->next){
                if(!strcmp(tmp->str, tmp2->str)){
                    ris = 1;
                }else{
                    ris = 0;
                }
            }
        }
    
    }else{
        printf("Almeno una lista nulla\n");
        ris = 0;
    }

    return ris;

}

int lunghezza(parola_t *p){
    
    int l;

    for(l = 0; p; p = p->next, l++);

    return l;
}

void visualizza(parola_t *h){
    for(; h; h = h->next){
        printf("%s ", h->str);
    }

    printf("\n");

}

parola_t* distruggi(parola_t *h){

    parola_t *tmp;
    for(; h; h = h->next){
        tmp = h;
        free(tmp);
    }

    return 0;
}