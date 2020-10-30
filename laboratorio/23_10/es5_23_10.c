/*es5 del laboratorio del 23/10*/

#include <stdio.h>
#include <string.h>

#define SDIM 20

int main(){

	char str[SDIM + 1];
	int i, j, grado_parentesi, corretta_par, size;

	scanf("%s", str);

	size = strlen(str);

	for(i = 0, grado_parentesi = 0; i < size && grado_parentesi >= 0; i++){ 
		/*
			verificando che grado_parentesi sia sempre maggiore o uguale a zero impongo che
			valgano solamente quelle stringhe in cui una parentesi chiusa è sempre preceduta da una parentesi aperta
		*/
		if(str[i] == '('){
			grado_parentesi++;
		}
		if(str[i] == ')'){
			grado_parentesi--;
		}
	}

	corretta_par = grado_parentesi == 0;

	if(corretta_par){
		printf("Corretta parentesizzazione\n");
	}else{
		printf("parentesizzazione errata\n");
	}


	return 0;
}