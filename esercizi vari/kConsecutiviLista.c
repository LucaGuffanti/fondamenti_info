#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_{
	int n;
	struct nodo_* next;
}	nodo_t;

int kCon(nodo_t*, int);
int kNoCon(nodo_t*, int);

int kCon(nodo_t* h, int k){
	nodo_t* curr;
	nodo_t* succ;
	int found;

	succ = h->next;
	curr = h;

	for(found = 0; succ && succ->next && !found; curr = succ, succ = succ->next){
		found = succ->n == k && curr->n == k; 
	}

	return found;
}

int kNoCon(nodo_t* h, int k){
	nodo_t* curr;
	nodo_t* curr2;
	int found;

	
	for(found = 0, curr = h; curr && !found; curr = curr->next){
		for(curr2 = curr->next; curr2 && !found; curr2 = curr2->next){
			found = curr->n == k && curr2->n == k;
		}
	}


	return found;
}