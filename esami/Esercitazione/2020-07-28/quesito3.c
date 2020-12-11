#include <stdio.h>
#include <math.h>

void meanvarstd(int[], int, float*, float*, float*);
void meanvarstdpos(int[], int, float*, float*, float*);


void meanvarstd(int seq[], int dim, float *mean, float *var, float *stdev){
	int i;
	float somma;

	for(i = 0, somma = 0; i < dim; i++){
		somma+=seq[i];
	}
	*mean = (somma)/(dim);

	for(i = 0, somma = 0; i < dim; i++){
		somma += (seq[i] - *mean)*(seq[i] - *mean);
	}

	*var = somma/dim;
	*stdev = sqrt(*var);
}

void meanvarstdpos(int seq[], int dim, float *mean, float *var, float *stdev){
	int i, n_pos;
	float somma;

	for(i = 0, n_pos = 0, somma = 0; i < dim; i++){
		if(seq[i] > 0){
			somma+=seq[i];
			n_pos++;	
		}
		
	}

	if(n_pos != 0){
		*mean = (somma)/(n_pos);

		for(i = 0, somma = 0; i < dim; i++){
			somma += (seq[i] - *mean)*(seq[i] - *mean);
		}

		*var = somma/n_pos;
		*stdev = sqrt(*var);
	}else{
		*mean = *stdev = *var = 0;
	}
}