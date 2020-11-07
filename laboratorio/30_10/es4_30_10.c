#include <stdio.h>

typedef struct{
	int x;
	int y;

} punto_t;

typedef struct{

	punto_t vsx;
	punto_t vdx;

} rettangolo_t;

int main(){

	rettangolo_t r1, r2, rint;
	int area1, area2, areaint;
	float frazione;

	do{
		printf("Inserire le coordinate dei vertici di r1: \n");

		scanf("%d%d", &r1.vsx.x, &r1.vsx.y);
		scanf("%d%d", &r1.vdx.x, &r1.vdx.y);

	}while(r1.vsx.x >= r1.vdx.x || r1.vsx.y >= r1.vdx.y);
	do{
		printf("Inserire le coordinate dei vertici di r2: \n");

		scanf("%d%d", &r2.vsx.x, &r2.vsx.y);
		scanf("%d%d", &r2.vdx.x, &r2.vdx.y);

	}while(r2.vsx.x >= r2.vdx.x || r2.vsx.y >= r2.vdx.y);

	area1 = (r1.vdx.x - r1.vsx.x) * (r1.vdx.y - r1.vsx.y);
	area2 = (r2.vdx.x - r2.vsx.x) * (r2.vdx.y - r2.vsx.y);

	printf("%d * %d = %d\n", r1.vdx.x - r1.vsx.x, r1.vdx.y - r1.vsx.y, area1 );
	printf("%d * %d = %d\n", r2.vdx.x - r2.vsx.x, r2.vdx.y - r2.vsx.y, area2 );


	if(r1.vsx.x == r2.vsx.x && r1.vsx.y == r2.vsx.y && r1.vdx.x == r2.vdx.x && r1.vdx.y == r2.vdx.y){

		rint.vsx.x = r1.vsx.x;
		rint.vsx.y = r1.vsx.y;
		rint.vdx.x = r1.vdx.x;
		rint.vdx.y = r1.vdx.y;
	}

	if(r1.vsx.x < r2.vsx.x){

		if(r1.vdx.x >= r2.vsx.x && r1.vdx.x <= r2.vdx.x){
			rint.vdx.x = r1.vdx.x;
			rint.vsx.x = r2.vsx.x;
		}
		else if(r1.vdx.x > r2.vdx.x){
			rint.vsx.x = r2.vsx.x;
			rint.vdx.x = r2.vdx.x;
		}
		else{
			rint.vsx.x = 0;
			rint.vsx.y = 0;
			rint.vdx.x = 0;
			rint.vdx.y = 0;
		}
	}else{

		if(r2.vdx.x >= r1.vsx.x && r2.vdx.x <= r1.vdx.x){
			rint.vdx.x = r2.vdx.x;
			rint.vsx.x = r1.vsx.x;
		}
		else if(r2.vdx.x > r1.vdx.x){
			rint.vsx.x = r1.vsx.x;
			rint.vdx.x = r1.vdx.x;
		}
		else{
			rint.vsx.x = 0;
			rint.vsx.y = 0;
		}
	}

	if(r1.vsx.y < r2.vsx.y){
		if(r1.vdx.y >= r2.vsx.y && r1.vdx.y <= r2.vdx.y){
			rint.vdx.y = r1.vdx.y;
			rint.vsx.y = r2.vsx.y;
		}
		else if(r1.vdx.y > r2.vdx.y){
			rint.vdx.y = r2.vdx.y;
			rint.vsx.y = r2.vsx.y;
		}
		else{
			rint.vsx.y = 0;
			rint.vdx.y = 0;
		}
	}else{
		if(r2.vdx.y >= r1.vsx.y && r2.vdx.y <= r1.vdx.y){
			rint.vdx.y = r2.vdx.y;
			rint.vsx.y = r1.vsx.y;
		}
		else if(r2.vdx.y > r1.vdx.y){
			rint.vdx.y = r1.vdx.y;
			rint.vsx.y = r1.vsx.y;
		}
		else{
			rint.vsx.y = 0;
			rint.vdx.y = 0;
		}

	}


	printf("Intersezione (se tutti 0, allora rettangoli disgiunti): \n");
	printf("(%d,%d)   (%d,%d)\n", rint.vsx.x, rint.vdx.y, rint.vdx.x, rint.vdx.y);
	printf("(%d,%d)   (%d,%d)\n", rint.vsx.x, rint.vsx.y, rint.vdx.x, rint.vsx.y);

	areaint = (rint.vdx.x - rint.vsx.x) * (rint.vdx.y - rint.vsx.y);

	printf("%d * %d = %d\n", rint.vdx.x - rint.vsx.x, rint.vdx.y - rint.vsx.y, areaint);

	frazione = (float)(areaint)/(area1 + area2);

	printf("Frazione dell'intersezione: %f\n", frazione);

	return 0;
}