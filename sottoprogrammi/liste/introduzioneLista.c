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

void visualizza(nodo_t *);
int lunghezza(nodo_t *);
int presente(nodo_t *, int);
nodo_t* presenteIndirizzo(nodo_t *, int);
nodo_t* inserisciInTesta(nodo_t *, int);
nodo_t* inserisciInCoda(nodo_t *, int);
nodo_t* eliminaElemento(nodo_t *, int);
nodo_t* eliminaOgniElemento(nodo_t *h, int ); /*fare come esercizio*/
void distruggiLista(nodo_t *);

/*versioni con i doppi puntatori*/
void inserisciInTestaDP(nodo_t **, int);


int main(){

	nodo_t *l1, *l2, *l3;
	nodo_t *curr;
	int num;

	/*le liste vanno sempre inizializzate a NULL, perché se non lo facciamo
	il puntatore punta a caso, e alla prima scansione della lista tutto crasha*/

	l1 = NULL;
	l2 = NULL;
	l3 = NULL;

	/*caricamento della prima lista*/
	scanf("%d", &num);

	while(num != 0){
		l1 = inserisciInCode(l1, num);
		scanf("%d", &num);
	}

	/*caricamento della seconda lista*/
	scanf("%d", &num);

	while(num != 0){
		l2 = inserisciInCoda(l2, num);
		scanf("%d", &num);
	}

	/*calcolo dell'intersezione tra le liste, eliminando i duplicati*/
	/*per ogni valore di l1, se quello è presente a l2, E non è presente in l3,
	allora posso inserire il valore in coda*/

	for(curr = l1; curr; curr = curr->next){
		if(presente(l2, curr->n) && !presente(l3, curr->n))
			l3 = inserisciInCoda(l3, curr->n);
	}

	visualizza(l3);

	distruggiLista(l1);
	distruggiLista(l2);
	distruggiLista(l3);

	return 0;
}

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
	nodo_t *elemento;

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