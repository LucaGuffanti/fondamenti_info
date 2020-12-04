/*
ES2.
Definire un nuovo tipo di dato per una lista concatenata che
permetta di memorizzare un polinomio; ciascun nodo della lista
memorizzerà un monomio in termini di due interi che rappresentano il
grado e il coefficiente di un dato monomio.
Scrivere un programma che chiede all'utente i dati di due polinomi.
L'acquisizione di ciascun polinomio termina quando l'utente
inserisce i dati 0 0 (che non andrà aggiunta alla lista) ed inoltre
va prestata attenzione al fatto che una lista non può contenere due
monomi con stesso grado; il programma deve prevenire tale
inserimento errato nella lista visualizzando anche un apposito
messaggio di errore. Si consiglia di organizzare ciascuna lista
ordinando i monomi in ordine decrescente del grado.
In seguito il programma esegue il prodotto e la somma tra i due
polinomi salvando il risultato in due nuove liste. Attenzione al
fatto che il prodotto tra due monomi può generare un monomio di
grado già presente nella lista risultato (e quindi ne va soltanto
aggiornato il coefficiente) o un nuovo monomio (che va quindi
aggiunto alla lista).
Il programma visualizza infine le quattro liste e, prima di
terminare, rilascia tutta la memoria allocata.
Si consiglia di strutturare il programma in vari sottoprogrammi.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
    int num;
    int g;
    struct nodo_ *next;
} nodo_t;

nodo_t* inserisciInTesta(nodo_t*, int, int);
nodo_t* somma(nodo_t*, nodo_t*);
nodo_t* prodotto(nodo_t*, nodo_t*);
void visualizza(nodo_t*);
nodo_t* distruggiLista(nodo_t*);

int main(){
    
    nodo_t *p1;
    nodo_t *p2;
    nodo_t *prod;
    nodo_t *som;
    int grado, valore;

    p1 = NULL;
    p2 = NULL;
    prod = NULL;
    som = NULL;

    /*inserimento del polinomio 1*/
    printf("Inserire il polinomio 1\n");
    scanf("%d %d", &valore, &grado);

    while(valore != 0 || grado != 0){
        p1 = inserisciInTesta(p1, valore, grado);
        scanf("%d %d", &valore, &grado);

        if(valore == 0 && grado == 0){
            printf("Terminato polinomio 1\n");
        }
    }

    /*inserimento del polinomio 2*/
    printf("Inserire il polinomio 2\n");
    scanf("%d %d", &valore, &grado);

    while(valore != 0 || grado != 0){
        p2 = inserisciInTesta(p2, valore, grado);
        scanf("%d %d", &valore, &grado);

        if(valore == 0 && grado == 0){
            printf("Terminato polinomio 2\n");
        }
    }

    visualizza(p1);
    visualizza(p2);

    som = somma(p1, p2);
    prod = prodotto(p1, p2);

    printf("Somma\n");
    visualizza(som);
    printf("Prodotto\n");
    visualizza(prod);

    p1 = distruggiLista(p1);
    p2 = distruggiLista(p2);
    som = distruggiLista(som);
    prod =distruggiLista(prod);

    return 0;
}

nodo_t* inserisciInTesta(nodo_t *l, int val, int grado){
    
    nodo_t *tmp; 
    tmp = NULL;

    tmp = malloc(sizeof(nodo_t));
    if(tmp){
        tmp->num = val;
        tmp->g = grado;

        tmp->next = l;
        l = tmp;
    }else{
        printf("Errore nell'allocazione\n");
    }

    return l;
}

nodo_t* somma(nodo_t *l1, nodo_t *l2){
    nodo_t *l3;
    nodo_t *monomio1;
    nodo_t *monomio2;
    int s;

    l3 = NULL;
    monomio1 = l1;
    for(; monomio1; monomio1 = monomio1->next){
        for(s = 0, monomio2 = l2; monomio2; monomio2 = monomio2->next){
            if(monomio1->g == monomio2->g){
                s = monomio1->num + monomio2->num;
            }
        }
        l3 = inserisciInTesta(l3, s, monomio1->g);
    }

    return l3;
    
}

nodo_t* prodotto(nodo_t *l1, nodo_t *l2){

    nodo_t *l3;
    nodo_t *curr1, *curr2, *curr3;
    int prod, gr;
    int i, found;

    l3 = NULL;
    curr3 = NULL;

    for(curr1 = l1; curr1; curr1 = curr1->next){
        for(curr2 = l2; curr2; curr2 = curr2->next){
           prod = curr1->num * curr2->num;
           gr = curr1->g + curr2->g;

           for(curr3 = l3, found = 0; curr3 && !found; curr3 = curr3->next){
               if(curr3->g == gr){
                   found = 1;
                   curr3->num = curr3->num + prod;
               }
            }
            if(!found){
                l3 = inserisciInTesta(l3, prod, gr);
            }
        }
    }

    return l3;
}

void visualizza(nodo_t *l1){
    for(; l1; l1 = l1->next){
        printf("%dx^%d ", l1->num, l1->g);
    }
    printf("\n");
}

nodo_t* distruggiLista(nodo_t *l){
    nodo_t *tmp;
    for(; l; l = l->next){
        tmp = l;
        free(tmp);
    }
    return NULL;
}
