/*
Un elemento di una sequenza si dice basso se il suo valore è strettamente minore del valore dell’elemento che lo precede e di quello che lo segue;
il primo e l’ultimo elemento della sequenza, non avendo entrambi gli elementi precedente e successivo non sono mai definiti bassi. Si utilizzino le
strutture dati più opportune per un uso non sovrabbondante della memoria.
(5 pti) Scrivere un sottoprogramma cercabassi che ricevuto in ingresso un array di valori reali (e qualsiasi altro parametro ritenuto strettamente
necessario) restituisce al chiamante gli elementi bassi trovati nell’array e trasmette inoltre il numero di tali elementi.
Per esempio, se i valori ricevuti in ingresso sono
3.4 6.2 2.4 2.0 1.8 7.2 -3.1 -3.1 9.4 2.6 2.2 8.4 -3.1 5.4 2.1 7.4 -4.0 -11.4 -8.9
il sottoprogramma rileva i seguenti 5 elementi bassi :
1.8 2.2 -3.1 2.1 -11.4
(4 pti) Scrivere un programma che chiede all’utente quanti dati reali deve processare e intende fornire in ingresso, un valore strettamente positivo, e
fino a quando l’utente non fornisce una risposta valida la richiesta viene re-iterata, per poi procedere all’acquisizione. Il programma calcola
gli elementi bassi avvalendosi del sottoprogramma cercabassi, quindi chiama il sottoprogramma analizzabassi (il cui prototipo
è riportato di seguito) che si occupa di effettuare un’analisi dei dati e la loro visualizzazione grafica con librerie apposite. Terminata l’analisi il
programma principale si conclude.
void analizzabassi(float [], int);
*/

#include <stdio.h>
#include <stdlib.h>

float* cercaBassi(float [], int, int*);
void analizzaBassi(float [], int);

int main(){
    float *arr;
    float *elementiBassi;
    int len, len2, i;

    do{
        printf("Inserire la lunghezza dell'array\n");
        scanf("%d", &len);
    }while(len < 0);

    if(arr = malloc(sizeof(float) * len)){
        elementiBassi = cercaBassi(arr, len, &len2);
        AnalizzaBassi(elementiBassi, len2);
        free(arr);
        free(elementiBassi);
    }else{
        printf("Errore nell'allocazione\n");
    }

    return 0;
}

float* cercaBassi(float arr[], int len, int *len2){
    int i, prev;
    float* bassi;
    if(bassi = malloc(sizeof(float) * len)){
        for(i = 1, *len2 = 0; i < len - 1; i++){
            if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
                bassi[*len2] = arr[i];
                (*len2)++;
            }
        } 
    }
    return bassi;
}

void analizzaBassi(float arr[], int len){
    int i;

    printf("Nell'array d'ingresso sono presenti\n");
    printf("%d elementi bassi.\n");
    for(i = 0; i < len; i++){
        printf("%2.1f", arr[i]);
    }
    printf("\n");
}