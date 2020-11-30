#ifndef LISTA_H
#define LISTA_H


typedef struct nodo_ {
/*per non avere errori di sintassi, definisco il tipo
della struct con un nome specifico,
perché non posso usare un simbolo definito successivamente.
Assegno quindi alla struct il nome nodo_, e poi all'interno della
struttura posso definire tutto tranquillamente*/

	int n;
	struct nodo_ *next;

} nodo_t;

typedef struct nodo_compatto_{
	int n;
	int volte;
	struct nodo_compatto_ *next;

} nodo_compatto_t;

void visualizza(nodo_t *);
int lunghezza(nodo_t *);
int presente(nodo_t *, int);
nodo_t* presenteRitornoIndirizzo(nodo_t *, int);
nodo_t* inserisciInTesta(nodo_t *, int);
nodo_t* inserisciInCoda(nodo_t *, int);
nodo_t* inserisciInOrdine(nodo_t *, int);
nodo_t* eliminaElemento(nodo_t *, int);
nodo_t* eliminaOgniElemento(nodo_t *h, int ); /*fare come esercizio*/
void distruggiLista(nodo_t *);
nodo_t* scriviBinario(nodo_t *, char *);
nodo_t* leggiBinario(char *);
nodo_t* listaMedie(nodo_t*);
nodo_t* scambioCoppie(nodo_t*);
nodo_t* scambioCoppie2Variabili(nodo_t *);
nodo_t* mergeListe(nodo_t *, nodo_t *);

nodo_compatto_t* compattaLista(nodo_t *);

/*uso di doppi puntatori*/
void inserisciInTestaDP(nodo_t **, int);
void listaSegno(nodo_t *, nodo_t **, nodo_t **);
void listaPariDispari(nodo_t*, nodo_t **, nodo_t **);

/*funzioni di tipo ricorsivo*/
void visualizzaRicorsione(nodo_t *);
int lunghezzaRicorsione(nodo_t *);
int presenteRicorsione(nodo_t *, int);
nodo_t* inserisciInCodaRicorsione(nodo_t *, int);
nodo_t* inserisciInOrdineRicorsione(nodo_t *, int);

#endif