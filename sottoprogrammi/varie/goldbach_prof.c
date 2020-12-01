#include <stdio.h>

int primo(int);

int main(){

	int num, i;

	scanf("%d", &num);

	while(num <= 2 || num % 2 != 0){
		scanf("%d", &num);
	}

	for(i = 2; i <= num/2; i++){
		if(primo(i) && primo(num - i)){
			printf("%d + %d = %d\n", i, num-i, num);
		}
	}

	return 0;
}

int primo(int n){

	int p, i;

	for(i = 2, p = 1; i * i <= n && p; i++){
		
		if(n%i == 0){
			p = 0;
		}
	}

	return p;

}
