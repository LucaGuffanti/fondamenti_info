#include <stdio.h>
#include <string.h>

#define N_ELEM 96
#define DIM_NOME_ELEM 30
#define DIM_NOME_MOL 15
#define DIM_SYM 2

typedef struct _elem {
 int numAtomico;
 char nome[DIM_NOME_ELEM+1];
 char simbolo[DIM_SYM+1];
} elemChimico_t;

typedef struct _mol {
 elemChimico_t * atomi;
 struct _mol * next;
} molecola_t;

void visualizzaMolecola(molecola_t*);

void visualizzaMolecola(molecola_t* m){
  molecola_t* tmp, *scorr;
  int i, pres, compare;
  
  for(tmp = m, i = 0; tmp; tmp = tmp->next){
    printf("%s", tmp->atomi->nome);  
    }
  }
  
  for(tmp = m; tmp; tmp = tmp->next){
    for(curr = tmp, pres = 0; curr; curr = curr->next){
      if(!strcmp(curr->atomi->simbolo, tmp->atomi->simbolo))
        pres++;  
    }
    printf("%s_%d ",tmp->atomi->simbolo, pres);
    for(i = 0;i < pres-1; i++)
       tmp = tmp->next;
  }
}
