#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5

int* dijkstra(int v);
int* prim();
int min_dist(int dist[]);

int graph[N][N] =
  {
   0,2,1,0,0,
   2,0,1,2,4,
   1,1,0,2,0,
   0,2,2,0,3,
   0,4,0,3,0
  };
int visited[N] = {0,0,0,0,0}; 
  
int main(){
  int* dist = dijkstra(0);
  int i;
  for(i=0;i<N;i++){
    printf("the shortest path of 0 to %ld is %ld\n",i , dist[i]);
  }
  for(i=0;i<N;i++){
    visited[i] = 0;
  }
  int* parent = prim();
  for(i=0;i<N;i++){
    printf("the parent of %ld is %d\n",i,parent[i]);
  }
}

int* dijkstra(int v){
  int* dist = (int*)malloc(sizeof(int)*N);
  int i;
  for(i=0;i<N;i++){
    dist[i] = INT_MAX;
  }
  dist[v] = 0;
  for(i=0;i<N-1;i++){
    int u = min_dist(dist);
    visited[u] = 1;
    int v;
    for(v=0;v<N;v++){
      if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
	dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  return dist;
}

int min_dist(int* dist){
  int min = INT_MAX;
  int min_index;
  int i;
  for(i=0;i<N;i++){
    if(visited[i] == 0 && dist[i] < min){
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

int* prim(){
  int* parent = (int*)malloc(sizeof(int)*N);
  int* dist = (int*)malloc(sizeof(int)*N);
  int i;
  for(i=0;i<N;i++){
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  parent[0] = -1;

  for(i=0;i<N-1;i++){
    int u = min_dist(dist);
    visited[u] = 1;
    int v;
    for(v=0;v<N;v++){
      if(graph[u][v] && visited[v] == 0 && graph[u][v] < dist[v]){
	parent[v] = u;
	dist[v] = graph[u][v];
      }
    }
  }
  return parent;
}
