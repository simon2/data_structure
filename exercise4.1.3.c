#include<stdio.h>
#include<stdlib.h>

struct list{
    char * elem;
    struct list *next;
};

void print(struct list *p){
    if(p==NULL){
        printf("[]\n");
    }else{
        printf("[ %s",p->elem);
        for(p=p->next;p!=NULL;p=p->next){
            printf(", %s", p->elem);
        }
        printf("]\n");
    }
}

struct list *cons(char *s, struct list *p){
    struct list *t;
    t = (struct list *)malloc(sizeof(struct list));
    t -> elem = s;
    t -> next = p;
    return t;
}

struct list *safe_f(struct list *p, struct list *q){
    struct list *pt = q;
    if(p==NULL){
        if(q==NULL){
            return NULL;
        }else{
            return cons(q->elem, safe_f(NULL,q->next));
        }
    }else{
        return cons(p->elem, safe_f(p->next, q));
    }
}

int main(int argc, char *argv[]){
    struct list *p1, *p2;
    p1 = cons("blue", cons("yellow", cons("red", NULL)));
    p2 = cons("black", cons("white", NULL));
    print(safe_f(p1,p1));
}

