#include <stdio.h>

typedef struct{
	int v1, v2;

} intervallo_t;

intervallo_t acquisisci();
intervallo_t intersezione(intervallo_t, intervallo_t, int*);
int lunghezza(intervallo_t);
void visualizza(intervallo_t);

int main(){

	intervallo_t i1, i2, in;
	int lung, sovr;

	i1 = acquisisci();
	i2 = acquisisci();

	in = intersezione(i1, i2, &sovr);

	if(sovr){
		lung = lunghezza(in);

		visualizza(in);
		printf("lunghezza: %d\n", lung);
	}else{
		printf("Intervalli non sovrapposti\n");
	}

	return 0;
}

intervallo_t acquisisci(){

	intervallo_t i;
	int swap;

	scanf("%d%d", &i.v1, &i.v2);

	if(i.v1 > i.v2){
		swap = i.v1;
		i.v1 = i.v2;
		i.v2 = swap;
	}

	return i;
}

intervallo_t intersezione(intervallo_t i1, intervallo_t i2, int *sovrapposti){

	intervallo_t inters;

	if(!(i1.v2 <= i2.v1 || i1.v1 >= i2.v2)){
		
		if(i1.v1 > i2.v1){
			inters.v1 = i1.v1;
		}else{
			inters.v1 = i2.v1;
		}

		if(i1.v2 < i2.v2){
			inters.v2 = i1.v2;
		}else{
			inters.v2 = i2.v2;
		}

		*sovrapposti = 1;
	
	}else{

		*sovrapposti = 0;
		inters.v1 = 0;
		inters.v2 = 0;
	}

	return inters;

}

int lunghezza(intervallo_t i){
	return i.v2 - i.v1;
}

void visualizza(intervallo_t i){

	printf("%d --> %d\n", i.v1, i.v2);

}