#include <stdio.h>

#define MAXS 30

int main(){

	char str[MAXS+1], s2[MAXS+1];
	int i, k, isSegno;

	scanf("%[^\n]", str);
	for(i = 0, k = 0, isSegno = 0; str[i] != '\0'; i++){
		if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')){
			isSegno = 1;
		}else{
			isSegno = 0;
		}

		if(!isSegno){
			s2[k] = str[i];
			k++;
		}
	}
	s2[k] = '\0';
	printf("%s\n",s2);
}