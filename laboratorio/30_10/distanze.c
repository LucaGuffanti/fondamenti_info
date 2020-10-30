/*
Si vuole realizzare un programma "interattivo" che permette di gestire un percorso su uno spazio bidimensionale composto da una lista di località.
Dichiarare un tipo di dato per rappresentare una località su una cartina in termini di coordinate x e y (due interi) ed un nome (una stringa di al max 30 caratteri). Scrivere un programma in grado di gestire un massimo di 50 località. All'avvio il programma visualizza un menù con le seguenti funzionalità e chiede all'utente di selezionarne una:
1 - Inserire in coda una nuova località
2 - Inserire in una specificata posizione una nuova località
3 - Cancellare una località nella lista
4 - Visualizzare l'intero percorso
5 - Visualizzare la lunghezza complessiva dell'itinerario
6 - Visualizza la coppia di località (anche non consecutive nel percorso) la cui distanza è maggiore di qualsiasi altra coppia.
7 - Uscita
Implementare le funzionalità specificate come segue:
1 - L'inserimento in coda può avvenire solo se c'è ancora spazio disponibile nella struttura dati, altrimenti viene visualizzato un messaggio di errore. In caso positivo il programma chiede all'utente i dati di una località e la aggiunge in fondo al percorso già memorizzato.
2 - Anche l'inserimento in mezzo può avvenire solo se c'è ancora spazio disponibile nella struttura dati, altrimenti viene visualizzato un messaggio di errore. In caso positivo il programma chiede all'utente prima l'indice in cui inserire la nuova località e poi i dati della nuova località; il programma sposta in avanti tutte le località presenti dall'indice specificato in modo tale da creare spazio per i nuovi dati. Nel caso l'utente inserisca un indice non valido il programma visualizza un messaggio di errore e non procede con la richiesta dei dati e l'inserimento.
3 - Il programma chiede all'utente l'indice della località da cancellare. Se l'indice è valido rimuove i dati relativi altrimenti visualizza un messaggio di errore.
4 - Il programma stampa a video il percorso inserito dall'utente
5 - Il programma calcola la distanza del percorso. La distanza tra due località consecutive nell'elenco è calcolata mediante il teorema di Pitagora. Per il calcolo della radice quadrata utilizzare la funzione sqrt() presente nella libreria math.h. Si noti che per compilare il programma quando si una la libreria matematica bisogna aggiungere alla fine del comando di compilazione l'argomento "-lm". Quindi si compilerà come "gcc distanze.c -o distante -lm"
6 - Il programma identifica e visualizza la coppia di località (anche non consecutive nel percorso) la cui distanza è massima. Il calcolo è eseguibile solo se ci sono almeno due località inserite. Se ci fossero più coppie a pari distanza massima, il programma ne stampa una sola (VARIANTE: stampare tutte le coppie).
Se l'utente inserisce un valore sbagliato, il programma visualizza un messaggio di errore e poi nuovamente il menù.

 */

#include<stdio.h>
#include<math.h>
#include<string.h>

#define MAXPUN 50
#define MAXSTR 30

#define APPEND 1
#define INSERT 2
#define DELETE 3
#define DISPLAY 4
#define LUNGHEZZA 5
#define MAXDIST 6
#define QUIT 7


typedef struct {
  int x, y;
  char nome[MAXSTR+1];
} localita_t;

typedef struct {
  localita_t punti[MAXPUN];
  int num;
} lista_localita_t;

int main() {
  lista_localita_t l;
  int s, i, j, max_pos1, max_pos2;
  float distanza, max_dist, curr_dist;
  
  l.num = 0;
  do {
    printf("MENU:\n");
    scanf("%d", &s);
    if(s==APPEND) {
      if(l.num<MAXPUN){
        printf("Insert values: \n");
        scanf("%d %d %s", &l.punti[l.num].x, &l.punti[l.num].y, l.punti[l.num].nome);
        l.num++;
      } else
        printf("No memory\n");
    } else if(s==INSERT) {
      if(l.num<MAXPUN){
        printf("Specify index: \n");
        scanf("%d",&i);
        if(i>=0 && i<=l.num){
          for(j=l.num-1; j>=i; j--)
            l.punti[j+1]=l.punti[j];
          printf("Insert values: \n");
          scanf("%d %d %s", &l.punti[i].x, &l.punti[i].y, l.punti[i].nome);
          l.num++;
        } else
          printf("Wrong index\n");
      } else
        printf("No memory\n");
    } else if(s==DELETE) {
      printf("Specify index: \n");
      scanf("%d",&i);
      if(i>=0 && i<l.num){
        for(j=i; j<l.num-1; j++)
          l.punti[j]=l.punti[j+1];
        l.num--;
      } else
        printf("Wrong index\n");
    } else if(s==DISPLAY) {
      printf("Current Path:\n");
      for(i=0; i<l.num; i++)
        printf("%d - %d %d %s\n", i, l.punti[i].x, l.punti[i].y, l.punti[i].nome);
    } else if(s==LUNGHEZZA) {
      for(i=0, distanza=0; i<l.num-1; i++)
        distanza+= sqrt((l.punti[i].x-l.punti[i+1].x)*(l.punti[i].x-l.punti[i+1].x)+
                    (l.punti[i].y-l.punti[i+1].y)*(l.punti[i].y-l.punti[i+1].y));
      printf("Distance: %f\n",distanza);
    } else if(s==MAXDIST) {
      if(l.num>=2){
        max_pos1=0;
        max_pos2=1;
        max_dist = sqrt((l.punti[0].x-l.punti[1].x)*(l.punti[0].x-l.punti[1].x) + (l.punti[0].y-l.punti[1].y)*(l.punti[0].y-l.punti[1].y));
        for(i=0; i<l.num; i++)
          for(j=i+1; j<l.num; j++){
            curr_dist = sqrt((l.punti[i].x-l.punti[j].x)*(l.punti[i].x-l.punti[j].x) + (l.punti[i].y-l.punti[j].y)*(l.punti[i].y-l.punti[j].y));
            if(curr_dist>max_dist){
              max_dist = curr_dist;
              max_pos1=i;
              max_pos2=j;
            }
          }
        printf("Most distant points: %s -> %s\n",l.punti[max_pos1].nome,l.punti[max_pos2].nome);
      } else
        printf("<2 Points\n");
    } else if(s!=QUIT) {
      printf("Error\n");
    }
  } while(s!=QUIT);
  
  return 0;
}
