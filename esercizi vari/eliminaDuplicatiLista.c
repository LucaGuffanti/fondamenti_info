nodo_t* UnisciArrayInLista(int [], int [], int, int);
nodo_t* eliminaDuplicati(nodo_t*);
nodo_t* inserisciInTesta(nodo_t*, int);

nodo_t* UnisciArrayInLista(int v1[], int v2[], int d1, int d2){
 nodo_t* h;
 int i;
 h = NULL;
 
 for(i = 0; i < d1; i++)
   h = inserisciInTesta(h, v1[i];
 for(i = 0; i < d2; i++)
   h = inserisciInTesta(h, v2[i];

 return eliminaDuplicati(h);
}

nodo_t* inserisciInTesta(nodo_t* h, int num){
 nodo_t* tmp;

 tmp = malloc(sizeof(nodo_t));
 if(tmp){
  tmp->n = num;
  tmp->next = h;
  h = tmp; 
 }else{
  prtinf("errore nell'allocazione del nodo\n");
 }
 return h;
}

nodo_t* eliminaDuplicati(nodo_t* h){
 
 nodo_t* i;
 nodo_t* curr;
 nodo_t* tmp;
 
 for(curr = h; curr; curr = curr->next){
  for(i = curr->next; i; i = i->next){
     if((i->next)->n == curr->n)
       tmp = (i->next);
       i->next = (i->next)->next;
       free(tmp);
   }
 }
 return h;
}