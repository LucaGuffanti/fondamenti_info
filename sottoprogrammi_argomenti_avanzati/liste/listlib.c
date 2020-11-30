/*libreria di funzioni per operare sulle liste*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_ {
/*per non avere errori di sintassi, definisco il tipo
della struct con un nome specifico,
perché non posso usare un simbolo definito successivamente.
Assegno quindi alla struct il nome nodo_, e poi all'interno della
struttura posso definire tutto tranquillamente*/

	int n;
	struct nodo_ *next

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

void visualizza(nodo_t *h){
	/*
	poiche h è un parametro formale, posso scorrere direttamente
	la lista senza problemi, tanto passando per valore non ho problemi di
	perdita di informazioni, anche perché la testa vera e propria
	è contenuta nella variabile del main, e h in visualizza è solo una copia
	*/

	for(; h; h = h->next){
		printf("%d\n", h->n);
	}
}

int lunghezza(nodo_t *h){
	
	int lung;

	for(lung = 0; h; h->next, lung++);

	return lung;
}

int presente(nodo_t *h, int num){
	/*anche qui con h parametro formale, copio tutta la lista, e quindi
	non mi interesso di perdere la testa, nella sua analisi */
	for(; h && h->n != num; h = h->next);
	/*prima verifico che il puntaore punti a qualcosa, e poi posso verificare i valori*/
	/*importante l'ordine di verifica delle condizioni: da sinistra a destra
	se h è diverso da null allora possiamo accedere al valore, la condizione al
	contrario fa crashare il programma*/
	return h != NULL;
	/*per lo stesso motivo, se sono alla fine della lista e cerco di verificare
	il contenuto del campo n, mi trovo un altro errore di segmentazione*/
}

nodo_t* presenteIndirizzo(nodo_t *h, int num){

	int found;
	nodo_t* elemento;

	elemento = NULL;
	for(found = 0; h && !found; h = h -> next){
		if(h->n == num){
			elemento = h;
			found = 1;
		}
	}

	return elemento;
}

nodo_t* inserisciInTesta(nodo_t *h, int num){
	nodo_t *tmp;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){

		tmp->n = num;
		tmp->next = h;
		h = tmp;

	}else{
		printf("Errore\n");
	}
	/*se memoria allocata bene, h è la nuova testa,
	sennò è la vecchia testa. h è sempre un paramentro formale
	ed è modificato nel chiamato. per avere una modifica 
	effettiva, poi la ritorno*/

	return h;
}

nodo_t* inserisciInCoda(nodo_t *h, int num){
	/*importantissimo controllare la situazione con lista vuota*/
	nodo_t *tmp;
	nodo_t *curr;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){

		tmp->n = num;
		tmp->next = NULL;

		if(h){

			for(curr = h; curr->next != NULL; curr = curr->next);
			/*la condizione la posso usare SE E SOLO SE ho già
			verificato che la lista non è vuota*/

			curr->next = tmp;

		}else{
			/*inserimento in testa dell'elemento nel momento in cui
			la lista è vuota in partenza*/
			h = tmp;
		}

	}else{
		printf("Errore nell'allocazione\n");
	}

	return h;

}

nodo_t* eliminaElemento(nodo_t *h, int num){

	nodo_t *curr;
	nodo_t *prec;
	int found;

	found = 0;
	curr = h;
	prec = NULL;

	while(curr && !found){
		if(curr->n == num){
			found = 1;
			if(prec){
				prec->next = curr->next;
			}else{
				h = curr->next;
			}

			free(curr);
		}else{
			prec = curr;
			curr = curr->next;
		}
	}

	return h;
}

nodo_t* eliminaOgniElemento(nodo_t *h, int num){

}

void distruggiLista(nodo_t *h){

	nodo_t *tmp;

	while(h){
		tmp = h;
		h = h->next;
		free(tmp);
	}
}

nodo_t* inserisciInOrdine(nodo_t *h, int num){
	nodo_t *prec;
	nodo_t *curr;
	nodo_t *tmp;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){
		tmp->n = num;
		tmp->next = NULL;

		if(h && num > h->n){
			for(prec = h, curr = h->next; curr && num > curr->n; prec = curr, curr = curr->next);
			
			tmp->next = curr;
			prec->next = tmp;
		}else{
			tmp->next = h;
			h = tmp;
		}
	}else{
		printf("errore malloc\n");
	}
	
}


void inserisciInTestaDP(nodo_t **h, int num){

	nodo_t *tmp;

	tmp = malloc(sizeof(nodo_t));

	if(tmp){

		tmp->n = num;
		tmp->next = *h;
		*h = tmp;

	}else{
		printf("Errore di allocazione\n");
	}
}


void visualizzaRicorsione(nodo_t *h){

	if(!h){
		return;
	}else{
		printf("%d\n", h->n);
		visualizzaRicorsione(h->next);
	}

}

int lunghezzaRicorsione(nodo_t *h){
	
	if(!h){
		return 0;
	}else{
		return 1 + lunghezzaRicorsione(h->next);
	}
}

int presenteRicorsione(nodo_t *h, int num){
	if(!h){
		return 0;
	}
	else if(h->n == num){
		return 1;
	}else{
		return presente(h->next, num);
	}
}

nodo_t* inserisciInCodaRicorsione(nodo_t *h, int num){
	if(!h){
		return inserisciInTesta(h, num);
	}else{
		h->next = inserisciInCodaRicorsione(h->next, num);
		return h;
	}
}

nodo_t* inserisciInOrdineRicorsione(nodo_t *h, int num){
	if(!h || h->n > num){
		return inserisciInTesta(h, num);
	}else{
		h->next = inserisciInOrdineRicorsione(h->next, num);
		return h;
	}
}

nodo_t* scriviBinario(nodo_t* h, char* filename){
	
	FILE *fp;

	fp = fopen(filename, "wb");
	if(fp){

		while(h){
			fwrite(&(h->n), sizeof(int), 1, fp);
			h = h->next;
		}

		fclose(fp);

	}else{
		printf("Errore di apetura\n");
	}
}

nodo_t* leggiBinario(char *filename){

	FILE *fp;
	int num;
	nodo_t *h;

	h = NULL;

	fp = fopen(filename, "rb");
	if(fp){

		fread(&num, sizeof(int), 1, fp);
		while(!feof(fp)){
			h = inserisciInCoda(h, num);
			fread(&num, sizeof(int), 1, fp);
		}

	}else{
		printf("Errore nell'apertura\n");
	}
}

nodo_t* listaMedie(nodo_t *h){
	
	nodo_t *l2;
	nodo_t *prec, *curr;
	int num;

	l2 = NULL;
	if(h){
		prec = h;
		curr = h->next;

		for(; curr; prec = curr, curr = curr->next){
			num = (prec->n + curr->n)/2;
			l2 = inserisciInCoda(l2, num);
		}

		l2 = inserisciInCoda(l2, prec->n);
	}else{
		printf("Lista vuota, ritorno NULL\n");
	}


	return l2;
}

nodo_t* scambioCoppie(nodo_t *h){

	nodo_t *l2;
	nodo_t *c;

	l2 = NULL;

	if(h){

		c = h;
		for(; c->next && c; c = (c->next)->next){
			l2 = inserisciInCoda(l2, c->next->n);
			l2 = inserisciInCoda(l2, c->n);
		}
		if(c) /*perché qui potrebbe essere uscito dal ciclo 
				perché non esiste il successivo, ma c potrebbe avere un nodo valido*/
			inserisciInCoda(l2, c->n);

	}else{
		printf("Lista vuota\n");
	}

	return l2;
}

nodo_t* scambioCoppie2Variabili(nodo_t *h){

	nodo_t *l2;
	nodo_t *curr, *prec;

	l2 = NULL;

	if(h){

		prec = h;
		curr = h->next;
		for(; prec && curr; prec = curr, curr = curr->next){
			l2 = inserisciInCoda(l2, curr->n);
			l2 = inserisciInCoda(l2, prec->n);
		}
		if(prec)
			inserisciInCoda(l2, prec->n);

	}else{
		printf("Lista vuota\n");
	}

	return l2;
}

void listaSegno(nodo_t *h, nodo_t **lp, nodo_t **ln){

	*lp = NULL;
	*ln = NULL;

	if(h){

		while(h){
			if(h->n > 0)
				*lp = inserisciInCoda(*lp, h->n);
			else
				*ln = inserisciInCoda(*ln, h->n);

			h = h->next;
		}

	}else{
		printf("Lista vuota\n");
	}

}

void listaPariDispari(nodo_t *h, nodo_t **ld, nodo_t **lp){

	*lp = NULL;
	*ld = NULL;

	if(h){

		while(h){
			if(h->n % 2 == 0)
				*lp = inserisciInCoda(*lp, h->n);
			else
				*ld = inserisciInCoda(*ld, h->n);

			h = h->next;
		}

	}else{
		printf("Lista vuota\n");
	}
}

nodo_t* mergeListe(nodo_t *l1, nodo_t *l2){

	nodo_t *h;
	nodo_t *tmp;
	h = NULL;

	tmp = h;

	while(l1 || l2){
		if(l1){
			h = inserisciInCoda(h, l1->n);
			l1 = l1->next;
		}
		if(l2){
			h = inserisciInCoda(h, l2->n);
			l2 = l2->next;
		}

	}

	return h;
}

nodo_compatto_t* compattaLista(nodo_t *h){
	nodo_compatto_t *l1;
	nodo_compatto_t *tmp;
	nodo_compatto_t *curr;
	l1 = NULL;
	int found;

	for(; h; h = h->next){
		for(curr = l1, found = 0; curr && !found; curr = curr->next){
			if(curr->n == h->n){
				found = 1;
				(curr->volte)++;
			}
			if(!found){
				tmp = malloc(sizeof(nodo_compatto_t));
				if(tmp){
					tmp->n = h->n;
					tmp->volte = 1;
					tmp->next = NULL;

					if(l1){
						for(curr = l1; curr->next; curr = curr->next);
						curr->next = tmp;
					}else{
						tmp->next = h;
						h = tmp;
					}
				}else{
					printf("Errore\n");
				}
			}
		}
	}

	return l1;
}