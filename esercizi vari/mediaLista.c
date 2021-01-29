nodo_t* listaConMedie(nodo_t*);


nodo_t* listaConMedie(nodo_t* h){
  int media, a1, a2;
  int i, len, j;
  nodo_t* ris; 
  nodo_t* tmp1;
  nodo_t* tmp2;
  
  ris = NULL;
  len = lunghezza(h);
  for(i = 0; i < len/2; i++){
    for(j = 0, tmp1 = h; j < len && tmp1 ; j++, tmp1 = tmp1->next){
      if(j == i){
        a1 = tmp1->n;
      }
      else if(j == len - i - 1){
        a2 = tmp1->n;
      }
    }
    media = (a1+a2)/2;
    ris = inserisciInCoda(ris, media);
  }  
  if(len%2 != 0){
    for(tmp1 = h, i = 0; tmp1 && i < len/2; i++);
    ris = inserisciInCoda(ris, tmp1->n);   
  }
}