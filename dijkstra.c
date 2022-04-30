#include <stdio.h>
#include <limits.h>

int min_dist(int dist[], int visited){
    int min = INT_MAX, min_index;
    int v;
    for(v=0;v<V;v++){
        if(visited[v] == 0 && dist[v] < min)
            min = dist[v];
            min_index = v;
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    int visited[V];
    int i;
    for(i=0;i<V;i++)
        dist[i] = INT_MAX;
        visited[i] = 0;
    dist[src] = 0;

    for(i=0;i<V;i++){
        int u = min_dist(dist, visited);
        visited[u] = 1;
        int v;

        for(v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && 
               dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                   dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}