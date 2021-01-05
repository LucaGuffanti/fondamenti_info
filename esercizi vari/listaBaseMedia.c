
nodo_t* inserisciPerMedia(int [], int);

nodo_t* inserisciPerMedia(int arr[], int dim){
 nodo_t* h;
 int i;
 int m;
 
 h = NULL;
 for(i = 0, m = 0; i < dim; i++){
   m += arr[i];
 }
 m = m/dim;
 
 for(i = 0; i < dim; i++){
   if(arr[i] <= m)
     h = inserisciInCoda(h, arr[i]);
 }

 return h;
}