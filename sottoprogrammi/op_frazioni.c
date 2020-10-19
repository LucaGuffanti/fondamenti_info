#include <stdio.h>

typedef struct{
	
	int num;
	int den;

} frazione_t;

frazione_t acquisisci();

frazione_t riduzione(frazione_t f);

frazione_t somma(frazione_t f1, frazione_t f2);

frazione_t prodotto(frazione_t f1, frazione_t f2);

int main(){

	frazione_t f1, f2, prod, som;
	int zero;

	f1 = acquisisci();
	f2 = acquisisci();

	f1 = riduzione(f1);
	f2 = riduzione(f2);

	som = somma(f1, f2);
	prod = prodotto(f1, f2);


	printf("f1 ridotta: %d/%d\n", f1.num, f1.den);
	printf("f2 ridotta: %d/%d\n", f2.num, f2.den);
	printf("somma: %d/%d\n", som.num, som.den);
	printf("prodotto: %d/%d\n", prod.num, prod.den);
	

	return 0;
}


frazione_t acquisisci(){

	frazione_t f;

	do{
		scanf("%d%d", &f.num, &f.den);

	}while(f.den == 0);

	if(f.num == 0){
		f.den = 1;
	}

	return f;
}


frazione_t riduzione(frazione_t f){

	int meno, mcd;

	if(f.num != 0){
		

		if(f.num < 0){
			
			f.num = -f.num;
			meno = 1;
		}else{

			meno = 0;
		}
		if(f.den < 0){
			
			meno = !meno;
			f.den = -f.den;
		}

		if(f.num > f.den){
			
			mcd = f.den;
		}else{
			
			mcd = f.num;
		}


		while(f.num % mcd != 0 || f.den % mcd != 0){
			mcd--;
		}

		if(meno){

			f.num = -f.num;
		}

		f.num = f.num / mcd;
		f.den = f.den / mcd;
	}
	return f;
}

frazione_t somma(frazione_t f1, frazione_t f2){

	frazione_t s;

	s.den = f1.den * f2.den;
	s.num = (f1.num * f2.den) + (f2.num * f1.den);

	s = riduzione(s);

	return s;
}

frazione_t prodotto(frazione_t f1, frazione_t f2){

	frazione_t p;

	p.num = f1.num * f2.num;
	p.den = f1.den * f2.den;

	p = riduzione(p);

	return p;
}