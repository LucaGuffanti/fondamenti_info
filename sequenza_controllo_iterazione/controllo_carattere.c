#include <stdio.h>

int main(){

	char c, c_new;
	scanf("%c", &c);
	
	if (c >= 'a' && c <= 'z'){
		c_new = c - 'a' + 'A';
		printf("%c\n", c_new);
	}
	else if (c >= 'A' && c <= 'Z'){
		c_new = c - 'A' + 'a';
		printf("%c\n", c_new);
	}else{
		printf("Carattere inserito non corretto.\n");
	}

	return 0;
}