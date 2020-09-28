#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);
	if(num > 0)
		printf("POS\n");
	else if(num < 0)
		printf("NEG\n");
	else
		printf("NULLO\n");

	return 0;
}