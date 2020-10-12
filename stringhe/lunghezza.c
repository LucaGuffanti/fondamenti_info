#include <stdio.h>

#define SDIM 30

int main(){

	char str[SDIM + 1];
	int len;

	scanf("%s", str);

	for(len = 0; str[len] != '\0'; len++);

	printf("%d\n", len);

	return 0;
}