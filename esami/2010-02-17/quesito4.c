#include <stdio.h>
#include <stdlib.h>


typedef struct frac_{
	int num;
	int den;
	struct frac_* next;
} frac_t;

int sottoSoglia(frac_t*, frac_t);
int inferiore(frac_t, frac_t);
frac_t* creaNodo(int , int );

int sottoSoglia(frac_t* h, frac_t soglia){
	float vFrac;
	float vSoglia;
	int cont;

	vSoglia = (float)(soglia.num)/soglia.den;

	for(cont = 0; h; h = h->next){
		vFrac = (float)(h->num)/h->den;
		if(vFrac == vSoglia){
			cont++;
		}
	}

	return cont;
}

int inferiore(frac_t f1, frac_t f2){
	float vF1, vF2;

	vF1 = (float)(f1.num)/f1.den;
	vF2 = (float)(f2.num)/f2.den;

	if(vF1 < vF2)
		return -1;
	else if(vF1 > vF2)
		return 1;
	else
		return 0;
}

frac_t* creadNodo(int n, int d){
	frac_t* tmp;

	tmp = NULL;
	tmp = malloc(sizeof(frac_t));
	if(tmp){
		tmp->next = NULL;
		tmp->num = n;
		tmp->den = d;
	}else{
		printf("Errore nell'allocazione.\n");
	}

	return tmp;
}