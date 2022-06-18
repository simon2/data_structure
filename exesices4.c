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

//4.2(2)
void insert_list(int x){
    struct list *p, *q, *t;
    q = NULL;
    for(p = head; p!=NULL; p = p->next){
        if(p->data>=x){
            break;
        }
        q = p;
    }
    t = (struct list *)malloc(sizeof(struct list));
    t -> data = x;
    if(q==NULL)
        head = t;
    else
        q->next = t;
    t -> next = p;
}

//4.2(3)
void delete_list(int x){
    struct list *p, *q;
    q = NULL;
    for(p=head;p!=NULL;p=p->next){
        if(p->data == x){
            if(q==NULL){
                head = p -> next;
            }else{
                q->next = p->next;
            }
            free(p);
            return;
        }
        q = p;
    }
}

//4.4
void init_pool(void){
    int i;
    for(i=1;i<SIZE-1;i++){
        pool[i].data = NUL;
        pool[i].next = i + 1;
    }
    pool[DHEAD].data = NUL;
    pool[DHEAD].next = TAIL;
    pool[PHEAD-1].next = TAIL;
    pool[PHEAD].data = NUL;
    pool[PHEAD].next = 1;
}

int node_alloc(){
    int p = pool[PHEAD].next;
    if(p==TAIL) exit(1);
    pool[PHEAD].next = pool[p].next;
    return (p);
}

void insert_node(int prev, int val){
    int p = node_alloc();
    pool[p].data = val;
    pool[p].next = pool[prev].next;
    pool[prev].next = p;
}

//(1) 在链表的最后插入一个值为val的新节点
void func1(int val){
    int prev = DHEAD;
    int pos = pool[prev].next;
    while(pos!=TAIL){
        prev = pos;
        pos = pool[pos].next;
    }
    insert_node(prev,val);
}

//(2) 删除链表中值为val的节点
void func2(int val){
    int prev = DHEAD;
    int pos = pool[prev].next;
    int p;
    while(pos != TAIL){
        if(pool[pos].data == val){
            p = pool[prev].next;
            pool[prev].next = pool[p].next;
            node_free(p);
            break;
        }else{
            prev = pos;
            pos = pool[pos].next;
        }
        
    }
}

//4.5(3)
int push(unsigned char data){
    if (sp <= 0)
        return -1;
    sp--;
    stack[sp] = data;
    /**/;
    return 1;
}

int pop(){
    unsigned char data;
    if(sp >= SIZE)
        return -1;
    /**/;
    data = stack[sp];
    sp++;
    return data;
}

int depth(){
    return SIZE - sp;
}

//4.9(1)
struct node *insert_node(int x, struct node *p){
    if(p==NULL){
        p = malloc();
        p -> data = x;//A
        p -> left = NULL;
        p -> right = NULL;
        return p;
    }

    if (x==p->data)
        return p;
    
    if(x<p->data)//B
        p->left = insert_node(x,p->left);//C
    else
        p->right = insert_node(x,p->right);//D
    return p;
}

//(2)
int sum_node(struct node *p){
    if(p==NULL)
        return 0;
    return p->data + sum_node(p->left) + sum_node(p->right);
}

//(3)
int search_node(int x, struct node *p){
    struct node *q;
    q = p;
    while(q){
        if(x == q->data){
            return 1;
        }
        if(x<q->data)
            q = q->left//;
        else
            q = q->right//;
    }
    return 0;
}

//4.13(1)
#define EMPTY -1
#define SKIP 3

int next(int x){
    x = x + SKIP;
    return x % MAX;
}

int search(int *table, int d){
    int h;
    h = hash(d);
    while(table[h] != EMPTY){
        if(table[h]==d) return h;
        h = next(h);
    }
    return -1;
}

//4.14

void traverse(int start, int goal){
    struct queue *q;
    int dist[N];
    int prev, node;
    for(node=0;node<N;node++){
        dist[node] = -1;
    }
    q = make_queue();
    dist[start] = 0;
    enqueue(q,start);
    printf("start from node", start);

    while(!is_empty()){
        prev = dequeue(q);
        for(node=0;node<N;node++){
            if(Adj[prev][node] == 1){
                if(dist[node] == -1){
                    dist[node] = dist[prev] + 1;
                    printf();
                    if(node == goal){
                        printf("path found...")
                    }
                    destroy_queue(q);
                    return;
                }else{
                    enqueue(q,node);
                }
            }
        }
    }
    printf("no path");
    destroy_queue(q);
}