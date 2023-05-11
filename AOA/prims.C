#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 5
void initializeSingleSource(int dist[], int par[], bool visited[], int source)
{
    int i;
    for (i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
        par[i] = -1;
        visited[i] = false;
    }
    dist[source] = 0;
}

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void relax(int u, int graph[][V], int dist[], bool visited[], int par[])
{
    int v;
    for (int v = 0; v<V; v++)
    {
        if (graph[u][v] &&  dist[u] + graph[u][v] < dist[v])
        {
            dist[v] = dist[u] + graph[u][v];
            par[v] = u;
        }
    }
}
void dijkstra(int graph[][V], int dist[], bool visited[], int par[], int source)
{
    int u, count;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        relax(u, graph, dist, visited, par);
        visited[u] = true;
}
}
int main () {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
    int source = 0;
    int dist[V], par[V];
    bool visited[V];
    initializeSingleSource(dist, par, visited, source);
    dijkstra(graph, dist, visited, par, source);
    printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
	printf("%d - %d \t%d \n", par[i], i,graph[i][par[i]]);
}
