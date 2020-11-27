/*ES3 - Si vuole realizzare un programma che verifica se una griglia
di un Sudoku (https://it.wikipedia.org/wiki/Sudoku), anche
parzialmente riempita, sia valida o meno. In breve una griglia di un
Sudoku è una matrice 9x9 di interi e ciacuna posizione può contenere
un valore da 1 a 9 o esser vuota se la griglia non è stata ancora
completata. Una griglia, anche parzialmente, è valida se si
verificano tutte le seguenti condizioni:
* in ciascuna riga della matrice non si presenta alcuna ripetizione
dei numeri validi (da 1 a 9)
* in ciascuna colonna della matrice non si presenta alcuna
ripetizione dei numeri validi (da 1 a 9)
* dividendo la matrice 9x9 in 9 sottomatrici 3x3 non sovrapposte,
ciascuna sottomatrice non contiene alcuna ripetizione dei numeri
validi (da 1 a 9).
Realizzare il programma come segue:
- definire una costante VUOTO contenente il valore 0.
- definire un sottoprogramma "stampa_sudoku" che riceva come
argomento una matrice definita con 9 colonne e la stampi a video. Si
utilizzi uno spazio per indicare le celle vuote; opzionale:
disegnare le righe orizzontali e verticali che contornano l'intera griglia


- definire un sottoprogramma "leggi_testuale" che riceve come
argomento il nome di un file di testo e una matrice di interi
dichiarata con 9 colonne. Il sottoprogramma apre il file di testo,
contenente 9x9 valori interi, e popola la matrice con i dati letti
da file. Il sottoprogramma restituisce 1 se l'operazione è andata a
buon fine altrimenti 0. Si noti che si potrebbe verificare un errore
di apertura del file o il numero di valori letti potrebbe essere
erroneamente minore di 81 o un dato valore potrebbe essere al di
fuori dell'intervallo [1,9] o diversa da VUOTO. Il sottoprogramma
prima di ritornare stampa a video la causa dell'eventuale errore
riscontrato.
- definire un sottoprogramma "leggi_binari" che riceve come
argomento il nome di un file binario e una matrice di interi
dichiarata con 9 colonne. Il sottoprogramma apre il file binario,
contenente 9x9 valori interi, e popola la matrice con i dati letti
da file. Il sottoprogramma restituisce 1 se l'operazione è andata a
buon fine altrimenti 0. Si noti che si potrebbe verificare un errore
di apertura del file o il numero di valori letti potrebbe essere
erroneamente minore di 81 o un dato valore potrebbe essere al di
fuori dell'intervallo [1,9] o diversa da VUOTO. Il sottoprogramma
prima di ritornare stampa a video la causa dell'eventuale errore
riscontrato.
- definire un sottoprogramma "verifica_sudoku" che riceva come
argomento una matrice di interi dichiarata con 9 colonne e verifichi
che il sudoku associato sia valido. Il sottoprogramma restituisce 1
in caso affermativo; in alternativa stampa a video un messaggio per
ciascun errore riscontrato (cioè indici di riga o colonna o
quadrante che violano le regole) e restituisce 0.
- Scrivere un programma chiede all'utente il nome del file (una
stringa di al massimo 50 caratteri) e la modalità con cui aprirlo
(1: testuale, 2: binario). Mediante l'ausilio dei sottoprogrammi
sopra definiti, il programma legge la matrice dal file, la stampa a
video e verifica se la griglia è valida, stampando a video il
responso. Gestire opportunamente gli eventuali errori.
*/

#include <stdio.h>

#define VUOTO 0
#define DIM 9
#define FILENAME "mix.txt"

void stampa_sudoku(int [][DIM]);
int leggi_testuale(int [][DIM], char []);
int leggi_binario(int [][DIM], char[]);
int verifica_sudoku(int [][DIM]);

int main(){

    int m[DIM][DIM];
    int esito;
    esito = leggi_testuale(m, FILENAME);
    printf("%d\n\n", esito);
    
    if(esito){
        stampa_sudoku(m);
        printf("%d", verifica_sudoku(m));
    }


    return 0;
}

void stampa_sudoku(int s[][DIM]){
    int i, j;
    for(i = 0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            printf(" %d ", s[i][j]);
        }
        printf("\n");
    }
}

int leggi_testuale(int m[][DIM], char str[]){
    
    FILE* fp;

    int cont, esito, stop, i, j;

    fp = fopen(str, "r");
    if(fp){
        
        cont = 0;
        esito = 1;
        stop = 0;
        i = 0;
        j = 0;

        for(i = 0; i < 9 && !stop; i++){
            for(j = 0; j < 9 && !stop; j++){
                
                fscanf(fp, "%d", &m[i][j]);

                if(!(!feof(fp) && (m[i][j] >= 1 && m[i][j] <= 9 || m[i][j] == VUOTO))){
                    if((m[i][j] >= 1 && m[i][j] <= 9) || m[i][j] != VUOTO)
                        printf("numero non compreso tra 1 e 9 oppure VUOTO\n");
                    stop = 1;
                }else{
                    cont++;
                }
            }
        }
        
        if(cont == 81 && !stop){
            esito = 1;
            
        }else{
            if(cont != 81){
                printf("Non abbastanza numeri\n\n");
            }
            esito = 0;
        }
    }else{
        printf("Errore nell'apertura del file\n");
        esito = 0;
    }
    return esito;
}

int leggi_binario(int m[][DIM], char str[]){
    FILE* fp;

    int cont, esito, stop, i, j;

    fp = fopen(str, "rb");
    if(fp){

        cont = 0;
        esito = 1;
        stop = 0;
        i = 0;
        j = 0;

        for(i = 0; i < 9 && !stop; i++){
            for(j = 0; j < 9 && !stop; j++){
                
                fread(&m[i][j], sizeof(int), 1, fp);
                
                if(!(!feof(fp) && (m[i][j] >= 1 && m[i][j] <= 9 || m[i][j] == VUOTO))){
                    if(m[i][j] >= 1 && m[i][j] <= 9 || m[i][j] != VUOTO)
                        printf("numero non compreso tra 0 e 9");
                    stop = 1;
                }else{
                    cont++;
                }
            }
        }
        
        if(cont == 81 && !stop){
            esito = 1;
            
        }else{
            if(cont != 81){
                printf("Non abbastanza numeri\n\n");
            }
            esito = 0;
        }
    }else{
        printf("Errore nell'apertura del file\n");
    }
}

int verifica_sudoku(int m[][DIM]){

    int i, j, h, k, t;
    int riga, colonna, quadrato;
    int conta[DIM+1];

    riga = colonna = quadrato = 1;
    
    printf("Inizio\n");

    for(i = 0; i < DIM+1; i++){
        conta[i] = 0;
    }
    /*inizio col verificare tutte le righe*/
    for(i = 0; i < DIM && riga; i++){
        for(j = 0; j < DIM; j++){
            conta[m[i][j]]++;
            if(m[i][j] == 4)
                conta[m[i][j]]--;
        }
        for(j = 0; j < DIM+1; j++){
            if(conta[j] > 1 && j != VUOTO){
                riga = 0;
                printf("Errore nelle righe!\n");
            }
        }
        for(t = 0; t < DIM+1; t++){
            conta[t] = 0;
        }
    }

    if(riga){
        printf("Righe Buone!\n");
            /*continuo verificando le colonne*/
        for(j = 0; i < DIM && colonna; i++){
            for(i = 0; i < DIM; i++){
                conta[m[i][j]]++;
            }
            for(i = 0; i < DIM+1; i++){
                if(conta[i] > 1 && i != VUOTO){
                    colonna = 0;
                    printf("Errore nelle colonne!\n");
                }
            }
            for(t = 0; t < DIM+1; t++){
                conta[t] = 0;
            }
        }
        
        if(colonna){
            /*per ultima la parte difficilie: controllare le sottomatrici*/
            printf("Colonne Buone!\n");
            for(i = 0; i < DIM && quadrato; i += 3){
                for(j = 0; j < DIM && quadrato; j += 3){
                    for(h = i; h < i+3; h++){
                        for(k = j; k < j+3; k++){
                            conta[m[h][k]]++;
                        }
                    }
                    for(h = 0; h < DIM+1 && quadrato; h++){
                        if(conta[h] > 1 && h != VUOTO){
                            printf("Errore nelle sottomatrici!\n");
                            quadrato = 0;
                        }
                    }
                    for(t = 0; t < DIM+1; t++){
                        conta[t] = 0;
                    }
                }
            }
        }
        if(quadrato){
            printf("sottomatrici Buone!\n");
        }
    }

    return riga && colonna && quadrato;
}