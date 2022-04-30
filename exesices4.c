//4.1(1)
struct list{
    char * elem;
    struct list *next;
};

void print(strct list *p){
    if(p == NULL){
        printf("[]\n");
    }else{
        printf("[ %s", p->elem);
        for(p=p->next;p!=NULL;p=p->next)
            printf(", %s", p->elem);
        printf("]\n");
    }
}

//4.1(2)
int length(struct list *p){
    int n = 0;
    while(p!=NULL){
        n++;
        p = p -> next; 
    }
    return n;
}

int length_r(struct list *p){
    if(p==NULL){
        return 0;
    }else{
        return 1 + length_r(p->next);
    }
}

//4.1(3)(c)
struct list *safe_t(struct list *p, struct list *q){
    struct list *pt = q;
    if(p==NULL){
        if(q==NULL){
            return NULL;
        }else{
            return cons(q->elem,safe_f(NULL,q->next));
        }
    }else{
        return cons(p->elem,safe_f(p->next,q));
    }
}

//4.2(1)
int sum_list(void){
    struct list *p;
    int sum;

    sum = 0;
    p = head;
    while(p != NULL){
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}