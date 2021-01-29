int contaPrecedenti(nodo_t*, int);


int contaPrecedenti(nodo_t* h, int val){
 if(h->next == NULL || h->num == val)
   return 0;
 else
   return 1 + contaPrecedenti(h->next, val);
}