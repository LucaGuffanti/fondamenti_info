#include <stdio.h>

int mcd(int, int);

int main(){

	int n, m;
	scanf("%d%d", &n, &m);

	printf("%d\n", mcd(n, m));
	return 0;
}

int mcd(int n, int m){
	if(m == n)
		return n;
	else if(m > n)
		return mcd(m - n, n);
	else
		return mcd(m, n - m);
}

/*senza caso base o invocando la ricorsione sullo stesso problema ho un errore non sostenibile*/