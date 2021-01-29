void contaStelle(char*, int*, int*, int);

void contaStelle(char* fn, int* nUguale, int* nSup, int n){
 char c;
 int isSpace;
 int usefulInfo;
 FILE *fp;
 

 fp = fopen(fn, "r");
 if(fp){
   *nUguale = *nSup = 0;
   usefulInfo = 1;
   char(fp, "%c", &c);
   while(!feof(fp)){
     if(c == ' ')
       isSpace = 1;
     else if(usefulInfo && c >= '0' &&  c <= '5' && isSpace){
       usefulInfo = 0;
       isSpace = 0;
       if(c - '0' == n){
         (*nUguale)++;
       }else if( c - '0' > n){
         (*nSup)++;
       }
     }
    else if(c == '\n')
      isSpace = 0;
      usefulInfo = 1;
    else
      isSpace = 0;

    fscanf(fp, "%c", &c);
   }
 }else{
   printf("Errore nell'apertura del file\n");
 }
}