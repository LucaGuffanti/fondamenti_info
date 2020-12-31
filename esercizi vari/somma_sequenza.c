#include <stdio.h>
#include <stdlib.h>

#define MAXS 30
void analizzaStringa(char[], int*, int*);

int main(int argc, char* argv[]){

  int max, min;
  char str[MAXS+1];

  
  analizzaStringa("a1245b645c7de45", &max, &min);

  printf("%d, %d", max, min);
  return 0;
}

void analizzaStringa(char str[], int* max, int* min){

  int i, isNumber, somma, notMin;
  char numero;

  *max = 0;
  
  for(i = 0, somma = 0, notMin = 1, isNumber = 0; str[i] != '\0'; i++){
      if(str[i] >= '0' && str[i] <= '9'){
          numero = str[i] - '0';      
          somma += (int)(numero);  
          isNumber = 1;
      }else if(!(str[i] >= '0' && str[i] <= '9') && isNumber){
        isNumber = 0;
        if(somma > *max){
          *max = somma;
          if(notMin){
	          *min = somma;	
            notMin = 0;
	        }	
        }
        else if(somma < *min)
          *min = somma;

        somma = 0;
      }   
  }
  if(isNumber){
    if(somma > *max){
      *max = somma;
    }
    else if(somma < *min)
      *min = somma;
  }    
} 