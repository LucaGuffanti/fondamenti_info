#include <stdio.h>
#include<stdlib.h>

typedef struct N{
    int data;
    struct N *next;
}el;

el *add(el *l, int n){
    
    el *t=l;
    
    if(l==NULL){
        t=(el *)malloc(sizeof(el));
        t->data=n;
        t->next=NULL;
        return t;
    }
    
    while((t->next)!=NULL){
        t=t->next;
    }
    t->next=(el *)malloc(sizeof(el));
    t=t->next;
    t->data=n;
    t->next=NULL;
    return l;
}

void out(el *l){
    el *t=l;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

el *charge(el *l){
    l=add(l,3);
    l=add(l,5);
    l=add(l,8);
    l=add(l,4);
    l=add(l,8);
    l=add(l,5);
    l=add(l,3);
    l=add(l,8);
}

el *end(el *l){
    el *t;
    while(l!=NULL){
        t=l->next;
        free(l);
        return end(t);
    }
    return l;
}

int main(){
    
    
    el *l=NULL;
    el *t=l;
    
    l=charge(l);
    out(l);
    t=l;
    out(t);
    l=end(l);
    out(l);
    out(t);
    
    return 0;
}