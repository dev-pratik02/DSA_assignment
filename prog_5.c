#include <stdio.h>

#define MAX 10

// Function to perform BFS
void BFS(int graph[MAX][MAX], int vertices, int start) 
{
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) 
    {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < vertices; i++) 
        {
            if (graph[v][i] == 1 && !visited[i]) 
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// Function to perform DFS
void DFS(int graph[MAX][MAX], int vertices, int v, int visited[]) 
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < vertices; i++) 
    {
        if (graph[v][i] == 1 && !visited[i]) 
        {
            DFS(graph, vertices, i, visited);
        }
    }
}

int main() 
{
    int vertices = 5;
    int graph[MAX][MAX] = 
    {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int visited[MAX] = {0};
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++) 
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\nGraph Traversal starting from vertex 0\n");
    BFS(graph, vertices, 0);
    printf("DFS Traversal: ");
    DFS(graph, vertices, 0, visited);
    printf("\n");
    return 0;
}
