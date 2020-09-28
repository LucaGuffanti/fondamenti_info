#include <stdio.h>

int main(){
	
	int a, b, c, max, aux, terna;
	scanf("%d%d%d", &a, &b, &c);

	/*In questo modo posso operare sempre la differenza tra i quadrati, perché cerco il valore massimo e fisso uno degli altri due
	  per poter verificare sempre la stessa operazione logica.
	*/
	if(a > b && a > c){
		max = a;
	}
	else if (b > a && b > c){
		max = b;
		b = a;

	}else{
		max = c;
		c = a;
	}

	terna = (max * max) - (b * b) == (c * c);
	printf("%d\n", terna);


} 