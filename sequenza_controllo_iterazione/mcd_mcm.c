#include <stdio.h>

int main(){
	
	int num1, num2, mcd, mcm, i;

	scanf("%d%d", &num1, &num2);

	/*calcolo mcd*/
	if(num1 > num2){
		mcd = num1;
		mcm = num2;
	}else{
		mcd = num2;
		mcm = num1;
	}


	while(num1 % mcd != 0 || num2 % mcd != 0)
		mcd = mcd - 1;

	/*calcolo mcm*/
	
	while(mcm % num1 != 0 || mcm % num2 != 0)
		mcm = mcm + 1;

	printf("A: %d\nB: %d\nMCD: %d\nmcm: %d\n",num1, num2, mcd, mcm);

	return 0;
}