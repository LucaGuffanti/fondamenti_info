#include <stdio.h>
#define VOTO_MAX 30
#define VOTO_MIN 0
#define VOTO_PROMOZIONE 18

int main(){

	int v_1, v_2;
	float media;
	
	scanf("%d%d", &v_1, &v_2);

	if(!((v_1 <= VOTO_MAX && v_1 >= VOTO_MIN) && (v_2 <= VOTO_MAX && v_2 >= VOTO_MIN))){
		printf("I voti non sono stati inseriti correttamente.\n");
	}else{
		media = (float)(v_1 + v_2)/2.0;
		if(media < 18){
			printf("Studente bocciato.\n");
		}else{
			printf("Studente promosso.\n");
		}
		printf("Media degli esami: %f\n", media);
	}

	return 0;
}