#include <stdio.h>

int main(){
	float a, b, c, det;
	scanf("%f%f%f", &a, &b, &c);

	if(a != 0){
		det = b*b - 4*a*c;
		if(det > 0)
			printf("Due soluzioni.\n");
		else if(det < 0)
			printf("Equazione impossibile.\n");
		else
			printf("Due soluzioni coincidenti.\n");
	}else{
		printf("Errore. a = 0 -> Equazione di primo grado.\n");
	}

	return 0;
}