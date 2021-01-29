int kstringa(char*);

int kstringa(char str){
  int conta;
  int i, j;
  int k;

  for(i = 0, j = 1, conta = 0, k = 0; str[j] != '\0' && str[i] != '\0'; i++, j++){
    if(str[j] < str[i]){
     conta++;
    }
    else{
      if(conta > k)
       k = conta;
      
      conta = 0;
    }
  } 
  return k;
}