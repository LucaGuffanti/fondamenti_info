#include <stdio.h>

int main(){

	char operazione;
	float a, b, res;
	scanf("%f %c %f", &a, &operazione, &b);

	if(operazione == '+'){
		res = a + b;
		printf("%f\n", res);
	}
	else if(operazione == '-'){
		res = a - b;
		printf("%f\n", res);
	}
	else if(operazione == '/'){
		res = a / b;
		printf("%f\n", res);
	}
	else if(operazione == '*'){
		res = a * b;
		printf("%f\n", res);
	}else{
		printf("Errore. Simbolo inserito scorrettamente.\n");
	}

	return 0;
}