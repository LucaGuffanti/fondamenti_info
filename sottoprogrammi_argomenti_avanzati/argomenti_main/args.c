#include <stdio.h>


/*il main è una funzione, e comunica con il sistema operativo.
possiamo passare al prograrmma degli argomenti*/
int main(int argc, char *argv[]){

	int i;
	for(i = 0; i < argc; i++){
		printf("%s\n", argv[i]);
	}

	return 0;
}