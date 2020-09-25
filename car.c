#include<stdio.h>

int main(){
  char c_min, c_mai;
  printf("Inserisci un carattere: ");
  scanf("%c", &c_min); //qui no spazio perché sennò non si sblocca la scanf
  c_mai = c_min - 'a' +'A';
  printf("Maiuscolo: %c\n", c_mai);
  printf("Inserisci un carattere: ");
  scanf(" %c", &c_min); //lo spazio prima di %c elimina tutti i separatori
  c_mai = c_min - 'a' +'A';
  printf("Maiuscolo: %c\n", c_mai);
  return 0;
}