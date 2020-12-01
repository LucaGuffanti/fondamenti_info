#include <stdio.h>
#include <string.h>
#include <math.h> //nel compilatore mettere -lm

#define MAXPUN 50
#define MAXSTR 30
#define FDIM 30
#define MAXLOAD 50


#define APPEND 1
#define INSERT 2
#define DELETE 3
#define DISPLAY 4
#define LUNGHEZZA 5
#define MAXDIST 6
#define QUIT 7
#define BOUNDING_BOX 8
#define SAVEPATH 9
#define LOADPATH 10



typedef struct{
	int x, y;
	char nome[MAXSTR + 1];
} localita_t;

typedef struct{
	localita_t punti[MAXPUN];
	int num;	//indice del primo elemento non valido nell struttura dati
} lista_localita_t;


void cornice(lista_localita_t *);
void savePath(lista_localita_t *);
void loadPath(lista_localita_t *);

int main(){

	lista_localita_t l;
	int s; //input dell'utente
	int i, j;
	float dist;
	int max_pos1, max_pos2;
	float max_dist, curr_dist;

	l.num = 0;

	do{
		printf("SCELTA: \n");
		scanf("%d", &s);

		if(s == APPEND){

			if(l.num < MAXPUN){
				printf("Insert Values: \n");
				scanf("%d%d %s", &l.punti[l.num].x, &l.punti[l.num].y, l.punti[l.num].nome);
				
				l.num++;
			}else{
				printf("No memory\n");
			}

		}
		else if(s == INSERT){

			if(l.num < MAXPUN){
				printf("Index: \n");
				scanf("%d", &i);
				/*QUINDI L.NUM RIMANE SEMPRE MINORE DELLA DIMENSIONE*/
				if(i >= 0 && i <= l.num){
					for(j = l.num - 1; j >= i; j--){
						l.punti[j + 1] = l.punti[j];
					}

					printf("Insert values: \n");
					scanf("%d %d %s", &l.punti[i].x, &l.punti[i].y, l.punti[i].nome);
					
					l.num++;
				}else{
					printf("Invalid Index\n");
				}
			}else{
				printf("No memory\n");
			}

		}
		else if(s == DELETE){

			printf("Index: \n");
			scanf("%d", &i);

			if(i<= 0 && i < l.num){

				for(j = i; j < l.num-1; j++){
					l.punti[j] = l.punti[j + 1];
				}

				l.num--;
			}else{
				printf("Wrong index\n");
			}
		}
		else if(s == DISPLAY){

			printf("Current path:\n");
			for(i = 0; i < l.num; i++){
				printf("%d - %d %d %s\n", i, l.punti[i].x, l.punti[i].y,  l.punti[i].nome);
			}

		}
		else if(s == LUNGHEZZA){

			for(i = 0, dist = 0; i < l.num - 1; i++){
				dist += sqrt(
						  (l.punti[i].x - l.punti[ i + 1].x) *
						  (l.punti[i].x - l.punti[ i + 1].x) 
						  +
						  (l.punti[i].y - l.punti[ i + 1].y) *
						  (l.punti[i].y - l.punti[ i + 1].y)
					    );
			}

			printf("Total Distance: %f\n", dist);
		}
		else if(s == MAXDIST){

			if(l.num >= 2){

				max_pos1 = 0;
				max_pos2 = 1;

				max_dist = sqrt(
							(l.punti[0].x - l.punti[1].x) *
							(l.punti[0].x - l.punti[1].x) 
							+
							(l.punti[0].y - l.punti[1].y) *
							(l.punti[0].y - l.punti[1].y)
						);

				for(i = 0; i < l.num; i++){
					for(j = i + 1; j < l.num; j++){
					
						curr_dist = sqrt(
							(l.punti[i].x - l.punti[j].x) *
							(l.punti[i].x - l.punti[j].x) 
							+
							(l.punti[i].y - l.punti[j].y) *
							(l.punti[i].y - l.punti[j].y)
						);

						if(curr_dist > max_dist){
							max_dist = curr_dist;
							max_pos1 = i;
							max_pos2 = j;
						}
					}
				}

				printf("Most distant points: %s -> %s\n", l.punti[max_pos1].nome, l.punti[max_pos2].nome);

			}else{
				printf("Not enough positions\n");
			}
		}
		else if(s == BOUNDING_BOX){
			cornice(&l);
		}
		else if(s == SAVEPATH){
			savePath(&l);
		}
		else if(s == LOADPATH){
			loadPath(&l);
		}
		else if(s != QUIT){
			printf("Error\n");
		}


	}while(s != QUIT);



	return 0;
}



void cornice(lista_localita_t *l){
	int i;
	localita_t bl, tr;

	if(l->num > 0){
		bl.x = l->punti[0].x;
		bl.y = l->punti[0].y;
		tr.x = l->punti[0].x;
		tr.y = l->punti[0].y;

		for(i = 0; i < l->num; i++){
			if(l->punti[i].x < bl.x){
				bl.x = l->punti[i].x;
			}
			else if(l->punti[i].x > tr.x){
				tr.x = l->punti[i].x;
			}

			if(l->punti[i].y < bl.y){
				bl.y = l->punti[i].y;			
			}
			else if(l->punti[i].y > tr.y){
				tr.y = l->punti[i].y;
			}

			/*
			printf;
			*/
		}
	}else{
		printf("Percorso vuoto\n");
	}
}

void savePath(lista_localita_t *l){

	FILE *fp;
	char fn[FDIM + 1];
	int i;
	if(l->num > 0){
		printf("Name of the file (with extension):\n");
		scanf("%s", fn);
		
		fp = fopen(fn, "w");

		if(fp){
			for(i = 0; i < l->num; i++){
				fprintf(fp, "%s %d %d\n", l->punti[i].nome, l->punti[i].x, l->punti[i].y);
			}

			fclose(fp);
		}else{
			printf("Error: file not opened\n");
		}
	}else{
		printf("No path\n");
	}

}

void loadPath(lista_localita_t *l){
	
	FILE *fp;
	char fn[FDIM + 1];
	int i, ris;

	if(l->num == 0){
		printf("Name of the file (with extension):\n");
		scanf("%s", fn);

		fp = fopen(fn, "r");

		if(fp){

			l->num = 0;
			
			ris = fscanf(fp, "%s %d %d", l->punti[l->num].nome, &(l->punti[l->num].x), &(l->punti[l->num].y));
			while(ris > 0 && l->num < MAXLOAD){
					printf("%s %d %d\n", l->punti[l->num].nome, l->punti[l->num].x, l->punti[l->num].y);
					(l->num)++;
					ris = fscanf(fp, "%s %d %d", l->punti[l->num].nome, &(l->punti[l->num].x), &(l->punti[l->num].y));
					
			}		
		}else{
			printf("Error: file note opened\n");
		}
	}else{
		printf("Path already loaded\n");
	}
	

}