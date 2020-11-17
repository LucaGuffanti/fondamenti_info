/*sottostringa di dimensione massima comune a due stringhe di testo*/

#include <stdio.h>

#define STRDIM 100

void trova_sottostr_max(char [], char [], char []);

int main(){

	char v1[STRDIM + 1], v2[STRDIM + 1], v3[STRDIM + 1];

	scanf("%s %s", v1, v2); 

	trova_sottostr_max(v1, v2, v3);

	printf("Sottostringa di dimensione massima: %s\n", v3);


	return 0;
}

void trova_sottostr_max(char v1[], char v2[], char v3[]){
	int substr, len, maxlen, start;
	int i, j, h;


	maxlen = 0;
	start = 0;
	for(i = 0; v1[i] != '\0'; i++){
		
		for(j = 0, len = 0; v2[j] != '\0'; j++){
			
			substr = 1;

			for(h = 0, len = 0; v1[i + h] != '\0' && v2[j + h] != '\0' && substr; h++){
					
				if(v1[i + h] == v2[j + h])	
					len++;
				else
					substr = 0;
			}

			if(len > maxlen){
					
				maxlen = len;
				start = h - maxlen;
					
				for(h = start; h < maxlen; h++)
					v3[h - start] = v2[j + h];
			}
		}
	}

}