#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTHROWS 36000
#define MAXNUMBER 6

void calculateMatrix(int [][MAXNUMBER]);


int main(){

    int matrix[MAXNUMBER][MAXNUMBER];

    calculateMatrix(matrix);

    return 0;
}

void calculateMatrix(int matrix[][MAXNUMBER]){
    int throw1, throw2;
    int i;

    srand(time(NULL));
    
    for(i = 0; i < MAXTHROWS; i++){
        throw1 = rand()%6 + 1;
        throw2 = rand()%6 + 1;

        matrix[throw1][throw2]++; 
    }
}