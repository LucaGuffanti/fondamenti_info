#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_NAME 30
#define DIM_COUNTRY 20

typedef struct {
  char firstname[DIM_NAME+1];
  char lastname[DIM_NAME+1];
  int age;
  char country[DIM_COUNTRY+1];
} partecipant_t;


typedef struct part_{
  partecipant_t* part;
  struct part_* next;
} partlist_t;


typedef struct ;

int visualizzaPartecipanti(partlist_t*, char*, int);

int visualizzaPartecipanti(partlist_t* h, char* nation, int old){
 int cont;
 
 cont = 0;
 for(; h; h = h->next){
   if(!strcmp(nation, h->part->country) && h->part->age == old){
     cont++;
     printf("%s, %s, %d, %s", h->part->firstname, h->part->lastname, h->part->age, h->part->country);
   }
 }
 return cont;
}