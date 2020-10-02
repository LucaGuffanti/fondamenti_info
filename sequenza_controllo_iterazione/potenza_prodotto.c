#include <stdio.h>

int main(){

	int n , m, i, neg;
	float pot;

	scanf("%d%d", &n, &m);

	while(m <= 0 && n == 0){
		printf("Inserire nuovamente n.\n");
		scanf("%d", &n);
	}

	pot = 1;
	i = 0;
	neg = m < 0;

	if(m != 0){
		if(neg){
			m = -m;
			while(i < m){
				pot = pot * n;
				i = i + 1;
			}
			pot = 1/pot;
		}else{
			while(i < m){
				pot = pot * n;
				i = i + 1;
			}			
		}
	}	

	printf("%f\n", pot);

	return 0;
}