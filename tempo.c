#include <stdio.h>
#define SEC_IN_DAY 86400
#define SEC_IN_ORE 3600
#define SEC_IN_MIN 60

int main(){
	int sec, min, ore, gg;
	scanf("%d", &sec);
	gg = sec / SEC_IN_DAY;
	sec = sec % SEC_IN_DAY;
	ore = sec / SEC_IN_ORE;
	sec = sec % SEC_IN_ORE;
	min = sec / SEC_IN_MIN;
	sec = sec % SEC_IN_MIN;
	printf("%d gg\n%d ore\n%d min\n%d sec\n", gg, ore, min, sec);
	return 0;
}