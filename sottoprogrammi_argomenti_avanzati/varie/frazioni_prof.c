#include <stdio.h>

typedef struct{
	int n;
	int d;

} frac_t;

frac_t acquisisci();
frac_t semplifica(frac_t);
frac_t somma(frac_t, frac_t);
frac_t prodotto(frac_t, frac_t);
void stampa(frac_t); //procedura: sottoprogramma che non restituisce nulla ->void

int main(){
	frac_t a, b, s, p;

	//se definisco una variabile acquisisci 
	//mi devo ricordare che una variabile locale "nasconde" la
	//controparte globale  (e in generale dello scope più esterno e quindi nulla funzionerebbe)

	a = acquisisci();
	b = acquisisci();

	stampa(somma(a,b));
	stampa(prodotto(a,b));

	return 0;
}

frac_t acquisisci(){

	frac_t f;

	do{
		scanf("%d%d", &f.n, &f.d);
	
	}while(f.d == 0);

	return f;
}

frac_t semplifica(frac_t n){
	int mcd, meno;

	/*Ogni simbolo ha uno scope: 
		è definito in una parte del codice e può essere
		utilizzato solo in quella parte
	*/
	if(n.n >= 0){
		meno = 0;
	}else{
		meno = 1;
		n.n = -n.n; //qui abbiamo variabile.campo, in
					//gli elementi sono di natura totalmente diversa
	}

	if(n.d < 0){
		meno = !meno;
		n.d = -n.d;
	}

	if(n.n > n.d){
		mcd = n.d;
	}else{
		mcd = n.n;
	}

	while(n.n%mcd != 0 || n.d%mcd != 0){
		mcd--;
	}
	
	n.n /= mcd;
	n.d /= mcd;

	if(meno){
		n.n = -n.n;
	}

	return n;
}

frac_t somma(frac_t a, frac_t b){
	frac_t s;
	s.n = a.n * b.d + b.n * a.d;
	s.d = a.d * b.d;

	return semplifica(s);
}

frac_t prodotto(frac_t a, frac_t b){

	frac_t p;
	p.n = a.n * b.n;
	p.d = a.d * b.d;

	return semplifica(p);
}

void stampa(frac_t f){
	printf("%d/%d\n", f.n, f.d);

	return;
}