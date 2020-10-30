#include <stdio.h>

typedef struct{
	int n, d;
} frac_t;

void stampa(frac_t *);

int main(){
	frac_t a;

	scanf("%d%d", &a.n, &a.d);

	stampa(&a);

	return 0;
}

void stampa(frac_t *f){
	printf("%d/%d\n",(*f).n,(*f).d);

	printf("%d/%d\n",f->n, f->d);

	/*in generale
		f->sottostruct.campo.campo2[i];

		scanf("%d", &f->n);

		con un altro puntatore n ad un'altra struttura dati

		f->n->struttura
	*/
}