#include <stdio.h>
#include <string.h>


#define STRDIM 100

void sottostringa(char [], char [], char []);

int main(){

	return 0;
}

void sottostringa(char s1[], char s2[], char s3[]){

	int i, j, k, l1, l2;
	int *maxp, maxl;
	int isSub;

	l1 = strlen(s1);
	l2 = strlen(s2);

	for(i = 0, maxl = 0; i < l1 - maxl; i++){
		for(j = 0; j < l2 - maxl; j++){
		
		isSub = 1;
		k = 0;

		while(i + k < l1&& j + k < l2 - maxl && isSub){
			if(s1[i+k] != s2[j+k]){
				isSub = 0;
			}else{
				k++;
			}
			k++;
		}

		if(k > maxl){
			maxl = k;
			maxp = s1;
		}

	}

	for(k = 0; k < maxl; k++, maxp++){
		s3[k] = *(maxp);
	}

	s3[k] = '\0';

}