/*
Quesito 3 [7 pti]
Dato un array bidimensionale di valori interi positivi, ogni punto rappresenta la quota di un vulcano in una area. Quando un vulcano erutta il cratere
si apre ed esce la lava per cui la sua quota cresce di 2, e la lava che fuoriesce fa crescere di 1 anche la quota delle otto posizioni attorno, se hanno
una quota inferiore a quella del vulcano prima dell’eruzione (la lava scende ...). I due array di seguito riportano la situazione prima e dopo l’eruzione
dell’elemento in grassetto.
3 0 6 1 5 1 5 6 8 1     3 0 6 2 6 1 5 6 8 1
0 0 5 6 0 5 4 0 5 6     0 0 6 8 1 5 4 0 5 6
1 0 8 1 2 6 4 6 5 6     1 0 8 2 3 6 4 6 5 6
5 1 8 6 0 0 0 0 0 0     5 1 8 6 0 0 0 0 0 0
3 1 3 0 4 1 2 1 5 6     3 1 3 0 4 1 2 1 5 6
5 1 5 1 3 1 1 0 7 1     5 1 5 1 3 1 1 0 7 1
5 1 5 1 0 0 5 6 2 3     5 1 5 1 0 0 5 6 2 3
3 1 8 1 0 0 0 0 0 0     3 1 8 1 0 0 0 0 0 0
prima                   dopo
(5 pti) Scrivere un sottoprogramma che ricevuto in ingresso un array bidimensionale di interi, le coordinate del vulcano che erutta, e qualsiasi altro
parametro ritenuto strettamente necessario, modifica l’array iniziale aggiornandolo con la configurazione delle quote corrispondenti a dopo
l’eruzione.
Il numero di colonne dell’array bidimensionale dichiarato dal chiamante è specificato mediante una direttiva define del simbolo NC.
(2 pti) Scrivere un sottoprogramma visualizzamappa che ricevuto in ingresso un array bidimensionale di interi e qualsiasi altro parametro
ritenuto strettamente necessario visualizza la mappa delle quote (come quella prima riportata).
*/

#include <stdio.h>

#define NC 10

void eruzione(int [][NC], int, int);
void visualizzamappa(int [][NC]);

int main(){
    int i, j, val;
    int xVulc, yVulc;
    int vulcano[NC][NC];

    scanf("%d %d", &xVulc, &yVulc);
    
    for(i = 0; i < NC; i++){
        for(j = 0; j < NC; j++){
            scanf("%d", &val);
            vulcano[i][j] = val;
        }
    }
    eruzione(vulcano, xVulc, yVulc);
    visualizzamappa(vulcano);

}

void eruzione(int vulc[][NC], int xVulc, int yVulc){
    int i, j, vulcHeight;

    vulcHeight = vulc[xVulc][yVulc];
    for(i = xVulc - 1; i < 3; i++){
        for(j = yVulc - 1; j < 3; j++){
            if((i >= 0 && j >= 0) && (i < NC && j < NC)){
                if((xVulc != i && yVulc != j) && vulc[i][j] < vulcHeight){
                    vulc[i][j]++;
                }
            }
        }
    }
    vulcHeight += 2;
}

void visualizzamappa(int vulc[][NC]){
    int i, j;
    for(i = 0; i < NC; i++){
        for(j = 0; j < NC; j++){
            printf("%d ", vulc[i][j]);
        }
        printf("\n");
    }
}