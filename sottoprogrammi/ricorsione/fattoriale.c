#include <stdio.h>

int fattoriale(int);

int main(){
	int num;
	scanf("%d", &num);

    printf("%d\n", fattoriale(num));
    
    return 0;
}
/*RICORSIONE*/

int fattoriale(int n){
    if(n == 0 || n == 1) /*caso base*/
        return 1;
    else /*passo ricorsivo*/
        return n * fattoriale(n - 1);
}