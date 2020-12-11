#include <stdio.h>
#include <math.h>

void meanvarstd(int [], int, float, float, float);
void meanvarstdpos(int [], int, float, float, float);

void meanvarstd(int seq[], int dim, float media, float var, float stdev){
    int i;
    float somma;

    for(i = 0, somma = 0; i < dim; i++){
        somma += seq[i];
    }
    media = somma/((float)(dim));

    for(i = 0, somma = 0; i < dim; i++){
        somma += pow(seq[i]-media, 2);
    }

    var = somma/(float)(dim);
    stdev = sqrt(var);
}

void meanvarstdpos(int seq[], int dim, float media, float var, float stdev){
    int i;
    int conta;
    float somma;

    for(i = 0, somma = 0, conta = 0; i < dim; i++){
        if(seq[i]>0){
            somma += seq[i];
            conta++;
        }
        
    }
    media = somma/((float)(conta));

    for(i = 0, somma = 0; i < dim; i++){
        if(seq[i]>0){
            somma += pow(seq[i]-media, 2);
        }
    }

    var = somma/(float)(conta);
    stdev = sqrt(var);
}