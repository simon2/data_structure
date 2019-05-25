#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct Node Node;
struct Node{
  int v;
  int weight;
  Node* next;
};

void add_edge(int v, int w, int weight);
void travel();
void dfs_r(int v);
void dfs();

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
  travel();
  dfs();
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

void travel(){
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
