#include <stdio.h>
#include <limits.h>

#define V 9

int min_key(int key[], int visited[]){
    int min = INT_MAX, min_index;
    int v;
    for(v=0;v<V;v++){
        if(visited[v]==0 && key[v]<min)
            min = key[v], min_index = v;
    }
    return min_index;
}

void prim(int graph[V][V]){
    int parent[V];
    int key[V];
    int visited[V];
    int i;
    for(i=0;i<V;i++)
        key[i] = INT_MAX, visited[i] = 0;
    key[0] = 0;
    parent[0] = -1;

    for(i=0;i<V-1;i++){
        int u = min_key(key, visited);
        visited[u] = 1;
        int v;
        for(v=0;v<V;v++)
            if(graph[u][v] && visited[v]==0 && graph[u][v]<key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
}