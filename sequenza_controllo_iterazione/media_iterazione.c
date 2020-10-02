#include <stdio.h>

#define VOTOMIN 18
#define VOTOMAX 30

/*18 20 30 4*/

int main(){
	int voto, i, max, min, somma;
	float media;

	scanf("%d", &voto);

	if(voto >= VOTOMIN && voto <= VOTOMAX){
		//Inizializzo solo se c'è un voto valido.
		max = voto;
		min = voto;
		somma = voto;
		i = 1;

		scanf("%d", &voto);
		while(voto >= VOTOMIN && voto <= VOTOMAX){
			
			i = i + 1; //oppure i++;
			somma = somma + voto; //oppure anche somma += voto;
			
			if(voto > max){
				max = voto;
			}else{
				min = voto;
			}

			scanf("%d", &voto);
			
		}

		media = (float)(somma)/i;

		printf("Media dei voti: %f\nMassimo dei voti: %d\nMinimo dei voti: %d\n", media, max, min);

	} else{

		printf("Sequenza vuota.\n");
	}

	return 0;
}