#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF INT_MAX

typedef struct 
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} WeightedGraph;

// Create weighted graph
WeightedGraph* createWeightedGraph(int vertices) 
{
    WeightedGraph *graph = (WeightedGraph*)malloc(sizeof(WeightedGraph));
    graph->numVertices = vertices;
    
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = (i == j) ? 0 : INF;

    return graph;
}

void addWeightedEdge(WeightedGraph *graph, int src, int dest, int weight) 
{
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight; // Undirected
}

int findMinDistance(int dist[], bool visited[], int n) 
{
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    return minIndex;
}

void dijkstra(WeightedGraph *graph, int src) 
{
    int n = graph->numVertices;
    int dist[MAX_VERTICES], parent[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < n; count++) 
    {
        int u = findMinDistance(dist, visited, n);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph->adjMatrix[u][v] != INF &&
                dist[u] != INF && dist[u] + graph->adjMatrix[u][v] < dist[v]) 
                {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Print shortest distances and paths
    printf("Shortest paths from vertex %d:\n", src);
    for (int i = 0; i < n; i++) 
    {
        if (dist[i] == INF) 
        {
            printf("Vertex %d: No path\n", i);
        } else {
            printf("Vertex %d: Distance = %d, Path = ", i, dist[i]);
            // Print path
            int path[MAX_VERTICES], len = 0, cur = i;
            while (cur != -1) 
            {
                path[len++] = cur;
                cur = parent[cur];
            }
            for (int j = len - 1; j >= 0; j--) 
            {
                printf("%d", path[j]);
                if (j > 0) printf("->");
            }
            printf("\n");
        }
    }
}

int main() 
{
    WeightedGraph *graph = createWeightedGraph(5);

    addWeightedEdge(graph, 0, 1, 4);
    addWeightedEdge(graph, 0, 2, 1);
    addWeightedEdge(graph, 2, 1, 2);
    addWeightedEdge(graph, 1, 3, 1);
    addWeightedEdge(graph, 2, 3, 5);
    addWeightedEdge(graph, 3, 4, 3);

    dijkstra(graph, 0);

    free(graph);
    return 0;
}
