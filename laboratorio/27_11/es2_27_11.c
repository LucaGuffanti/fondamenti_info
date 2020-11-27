/*
ES2 - Il cifrario di Vigenere (https://it.wikipedia.org/wiki/
Cifrario_di_Vigenère) è una versione modificata del cifrario di
Cesare in cui il discostamento utilizzato nella codifica non è fisso
ma cambia carattere per carattere. In particolare, considerando una
stringa di testo CHIARO contenente un messaggio in chiaro e una
seconda stringa di testo CHIAVE che rappresenta la chiave e contiene
soltanto caratteri dell'alfabeto minuscolo, la criptazione avviene
come segue:
* ogni carattere della CHIAVE corrisponde ad un possibile
discostamento: a->0, b->1, c->2, ... z->25. La criptazione avviene
sostituendo un carattere con quello alla destra un numero di
posizioni dopo pari al discostamento; la decriptazione avviene
sostituendo il carattere con quello alla sua sinistra un numero di
posizioni prima pari al discostamento.
* il primo carattere di CHIARO viene criptato utilizzando il primo
carattere di CHIAVE, il secondo carattere di CHIARO mediante il
secondo carattere di CHIAVE e così via...
* quando i caratteri di CHIAVE finiscono si riparte dall'inizio per
la seguente parte del testo di CHIARO.
* se un carattere di CHIARO è diverso da una lettera dell'alfabeto
minuscolo, questo viene semplicemente copiato nel testo criptato e
l'indice al carattere corrente di CHIAVE non viene incrementato.
Esempio:
Se CHIAVE="abe" e CHIARO="ciao ciao", il messaggio verrà criptato
come segue:
CHIARO =ciao ciao
CHIAVE =abea beab
CRIPTATO=cjeo dmap
Si vuole realizzare un programma che implementa il cifrario di
Vigenere per un messaggio ed una chiave contenuti in dei file. In
particolare, nel file binario chiave.bin sono stati salvati in
sequenza un numero intero LUN ed una sequenza di caratteri di
lunghezza LUN; si assuma che il file sia ben formato quindi ci si
aspetta che il numero di caratteri contenuti dopo l'intero LUN siano
esattamente LUN, inoltre la stringa contenuta in chiave.bin NON è terminata dal carattere '\0'. Nel file di testo messaggio.txt è
stato salvato un messaggio di lunghezza indefinita criptato con il
cifrario di Vigenere mediante la chiave contenuta nel precedente
file.
In particolare:
* scrivere un sottoprogramma che riceve come parametro il nome di un
file binario contenente una chiave, il sottoprogramma legge la
chiave, salvandola in un array dinamico della dimensione
strettamente necessaria per contenerla (si ricordi di appendere in
fondo alla chiave il carattere terminatore, non presente nel file).
Il sottoprogramma restituisce l'array contenente la chiave o NULL
nel caso si sia verificato un qualsiasi errore.
* scrivere un sottoprogramma che riceve come parametri due caratteri
che rappresentano un carattere cifrato ed il passo da usare per la
decifratura. Il sottoprogramma decifra il carattere e lo
restituisce.
* scrivere un programma che acquisisce dal file chiave.bin una
chiave mediante il sottoprogramma sopra definito, apre il file di
testo messaggio.txt e decodifica il messaggio carattere per
carattere mostrandolo a video.
* il sottoprogramma infine rilascia tutte le risorse: file aperti e
memoria allocata dinamicamente.
Gestire tutti gli eventuali errori.
*/
/*'a' - 'a' ->questo diventa molto utile*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MESSAGGIO "messaggio.txt"
#define CHIAVE "chiave.bin"

char* leggiFile(char *);
char decifra(char, int);

int main(){

    FILE *fmex;
    char c, dec;
    char *key;
    int i, len;

    fmex = fopen(MESSAGGIO, "r");
    if(fmex){
        
        key = leggiFile(CHIAVE);
        len = strlen(key);
        i = 0;

        printf("%s\n", key);
        fscanf(fmex, "%c", &c);

        while(!feof(fmex)){
            printf("%c ->%c->", c, key[i%len]);
            if(c >= 'a' && c <= 'z'){
                c = decifra(c, key[i%len]);
                i++;
            }
            printf("%c\n", c);
            fscanf(fmex, "%c", &c);
        }

        printf("\n");
        fclose(fmex);
        free(key);
    }
    
    return 0;

}

char* leggiFile(char *filename){

    FILE *fp;
    char *text;
    int numeroCaratteri, i;

    text = NULL;
    fp = fopen(filename, "rb");

    if(fp){

        fread(&numeroCaratteri, sizeof(int), 1, fp);

        text = malloc(sizeof(char) * (numeroCaratteri + 1));
        
        if(text){

            fread(text, sizeof(char), numeroCaratteri, fp);
            text[numeroCaratteri] = '\0';

        }else{
            printf("Errore nell'allocazione della memoria\n");
        }
        fclose(fp);
    }else{
        printf("Errore nell'apertura del file\n");
    }
    return text;
}

char decifra(char carattere, int passo){

    char dec;
    char c;
        c = (carattere - (passo - 'a'));
        if(c < 'a'){
            /*il + 1 bisogna SEMPRE ricordarsi di metterlo perché sennò si arriva ad un elemento prima nell'underflow*/
            c += 'z' - 'a' + 1;
        }
        dec = c;
    return dec;
} 