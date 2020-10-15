#include <stdio.h>

typedef struct {

	int num;
	int den;

}frazione_t;

int main(){

	frazione_t f1, f2, fs;
	int i, mcd, meno;

	do{
		scanf("%d%d", &f1.num, &f1.den);
	}while(f1.den == 0);

	do{
		scanf("%d%d", &f2.num, &f2.den);
	}while(f2.den == 0);

	//Calcolo della somma

	fs.den = f1.den * f2.den;

	fs.num = (f1.num * f2.den) + (f2.num * f1.den);

	//Riduzione ai minimi termini

	if(fs.num >= 0){
		
		meno = 0;
	}
	else{ 
		
		meno = 1;
		fs.num = -fs.num;
	}

	if(fs.den < 0){
		
		fs.den = -fs.den;
		meno = !meno;
	}



	if(fs.num > fs.den){
		
		mcd = fs.den;
	}
	else{

		mcd = fs.num;
	}

	while(fs.num%mcd != 0 || fs.den%mcd != 0){
		mcd--;
	}

	fs.num = fs.num / mcd;
	fs.den = fs.den / mcd;

	if(meno){
		fs.num = -fs.num;
	}

	printf("%d/%d\n", fs.num, fs.den);

	return 0;
}