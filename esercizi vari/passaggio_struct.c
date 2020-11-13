#include <stdio.h>

#define DIM 10

typedef struct{

    int a;
    char text[DIM + 1];

} obj_t;

void loadStructByReference(obj_t *);
void printStructByReference(obj_t *);


int main(){

    obj_t o;

    loadStructByReference(&o);
    printStructByReference(&o);

    return 0;
}

void loadStructByReference(obj_t *o){
    scanf("%d", &(o->a));
    scanf("%s", o->text);
}

void printStructByReference(obj_t *o){
    printf("%d\n", o->a);
    printf("%s\n", o->text);
}