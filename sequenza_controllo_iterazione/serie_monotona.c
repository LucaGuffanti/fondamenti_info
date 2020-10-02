#include <stdio.h>

int main(){

	int x1, x2, monotona;

	scanf("%d", &x1);

	if(x1 != 0){
		scanf("%d", &x2);

		while(x2 != 0 && x2 > x1){
			x1 = x2;
			scanf("%d", &x2);
		}
		if(x2 == 0){
			printf("Serie terminata. Monotona fino all'elemento 0.\n");
		}else{
			printf("Serie non monotona crescente. Elemento errato: %d\n", x2);
		}
	}else{
		printf("Inserito l'elemento di fine serie. Serie nulla.\n");
	}

	return 0;
}