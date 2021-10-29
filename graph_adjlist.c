#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct Node Node;
struct Node{
  int v;
  int weight;
  Node* next;
};

typedef struct Queue{
  int* array;
  int front;
  int rear;
  int count;
  int length;
}Queue;

Queue createQueue();
void enqueue(Queue* queue, int x);
int dequeue(Queue* queue);
void add_edge(int v, int w, int weight);
void traverse();
void dfs_r(int v);
void dfs();
void bfs_r(int v);
void bfs();

Node** graph;
int visited[N] = {0,0,0,0,0}; 
  
int main(){
  graph = (Node**)malloc(sizeof(Node*)*N);
  int i;
  for(i=0;i<N;i++){
    graph[i] = NULL;
  }
  add_edge(0,1,1);
  add_edge(1,2,9);
  add_edge(3,1,1);
  add_edge(0,2,4);
  add_edge(2,3,3);
  add_edge(1,4,2);
  add_edge(3,4,7);
  traverse();
  //dfs();
  bfs();
}

void add_edge(int v, int w, int weight){
  if(v > N || w > N || v < 0 || w < 0){
    printf("No such vertex!\n");
    return;
  }
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->v = w;
  newNode->weight = weight;
  newNode->next = NULL;
  Node* p = graph[v];
  if(p == NULL){
    graph[v] = newNode;
    return;
  }else{
    newNode->next = graph[v];
    graph[v] = newNode;
  }
}

void traverse(){
  int i;
  for(i=0;i<N;i++){
    printf("vertex %ld: ", i);
    Node* p = graph[i];
    while(p){
      printf("%ld(%ld) ", p->v, p->weight);
      p = p->next;
    }
    printf("\n");
  }
}

void dfs_r(int v){
  if(visited[v]){
    return;
  }
  printf("%ld ", v);
  visited[v] = 1;
  Node *p = graph[v];
  while(p){
    if(!visited[p->v]){
      dfs_r(p->v);
    }
    p = p -> next;
  }
}

void dfs(){
  int i;
  for(i=0;i<N;i++){
    dfs_r(i);
  }
}

void bfs_r(int v){
  if(visited[v]){
    return;
  }
  Queue q = createQueue();
  enqueue(&q,v);
  visited[v] = 1;

  while(q.count != 0){
    v = dequeue(&q);
    printf("%d",v);
  
    Node* p = graph[v];
    while(p){
      if(!visited[p->v]){
	enqueue(&q,p->v);
	visited[p->v] = 1;
      }
      p = p -> next;
    }
  }
}

void bfs(){
  int i;
  for(i=0;i<N;i++){
    bfs_r(i);
  }
}

Queue createQueue(){
  Queue queue;
  queue.array = (int*)malloc(sizeof(int)*N);
  queue.front = 0;
  queue.rear = 0;
  queue.count = 0;
  queue.length = N;
  return queue;
}

void enqueue(Queue* queue, int x){
  if(queue->count >= queue->length){
    printf("The queue is full, you cannot enqueue any element into it!\n");
  }else{
    queue->array[queue->front] = x;
    if(queue->front == queue->length-1){//to deal with the boundary problem in circular queue.
      queue->front = 0;
    }else{
      queue->front++;
    }
    queue->count++;
  }
}

int dequeue(Queue* queue){
  int result = -1;
  if(queue->count==0){
    printf("The queue is empty, you cannot dequeue any element from it!\n");
  }else{
    result = queue->array[queue->rear];
    if(queue->rear == queue->length-1){//to deal with the boundary problem in circular queue.
      queue->rear = 0;
    }else{
      queue->rear++;
    }
    queue->count--;
  }
  return result;
}

