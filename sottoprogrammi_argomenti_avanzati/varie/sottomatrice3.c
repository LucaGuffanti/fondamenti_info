#include <stdio.h>

#define NC 5

void simile_media(int [][NC], int, int, int *, int *);

int main(){

	return 0;
}

void simile_media(int m[][NC], int nr_utilizzate, int nc_utilizzate, int *min_r, int *min_c ){

	int i, j;
	float media, min_dist, curr_dist;

	for(i = 0, media = 0; i < nr_utilizzate; i++)
		for(j = 0; j < nc_utilizzate; j++)
			media += m[i][j];

	media = media / (nr_utilizzate * nc_utilizzate);

	*min_r = 0;
	*min_c = 0;

	min_dist = media - m[*min_r][*min_c];
	if(min_dist < 0){
		min_dist = -min_dist;
	}

	for(i = 0; i < nr_utilizzate; i++){
		for(j = 0; j < nc_utilizzate; j++){
			curr_dist = media - m[i][j];
			if(curr_dist < 0){
				curr_dist = -curr_dist;
			}

			if(curr_dist <= min_dist){
				min_dist = curr_dist;
				*min_r = i;
				*min_c = j:
			}
		}
	}

}