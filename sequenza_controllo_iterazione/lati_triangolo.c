#include <stdio.h>

int main(){

	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);

	if(a > 0 && b > 0 && c > 0){
		if(a + b > c && a + c > b && c + b > a){
			printf("%f %f %f costituiscono i lati di un triangolo.\n", a, b, c);
			if(a == b && b == c){
				printf("Triangolo equilatero.\n");
			}
			else if(a == b || b == c || c == a){
				printf("Triangolo isoscele.\n");
			}else{
				printf("Triangolo scaleno.\n");
			}
		}else{
			printf("%f %f %f  non costituiscono i lati di un triangolo.\n", a, b, c);
		}
	}else{
		printf("Errore. Almeno uno dei valori e' minore o uguale a 0.\n");
	}

	return 0;
}