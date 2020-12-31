#include <stdio.h>
#include <stdlib.h>

#define OPEN '('
#define CLOSE ')'

typedef struct nodo_{
	char c;
	struct nodo_* next;
} nodo_t;

nodo_t* gestisciSequenza(nodo_t*);

nodo_t* gestisciSequenza(nodo_t* s){
	nodo_t* s2;
	int isOpen;

	s2 = NULL;

	for(isOpen = 0; s; s = s->next){
		if(s->c == OPEN){
			isOpen = 1;
			s2 = inserisciInCoda(s2, s->c);
		}
		else if(s->c == CLOSE){
			isOpen = 0;
			s2 = inserisciInCoda(s2, s->c);
		}
		else if(isOpen){
			if(s->next == CLOSE){			
				s2 = inserisciInCoda(s2, '#');
			}
		}
		else if(!isOpen){
			s2 = inserisciInCoda(s2, s->c);
		}
	}

	return s2;
}