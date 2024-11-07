// BFS IMPLEMENTATION

#include <stdio.h>

#define MAX 10

// Define the graph and visited array globally
int graph[MAX][MAX], visited[MAX], vertices;

void BFS(int start);

int main()
{
    // Input the number of vertices
    printf("Enter the number of vertices in the graph - ");
    scanf("%d", &vertices);
    
    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix...\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Initialize visited array to 0 (unvisited)
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    
    // Perform BFS starting from vertex 0
    printf("\nThe BFS traversal of the graph is - ");
    BFS(0);
    
    return 0;
}

void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;  // Enqueue the starting vertex

    while (front != rear)
    {
        int vertex = queue[front++];  // Dequeue the front vertex
        printf("%d ", vertex);

        // Explore the adjacent vertices
        for (int j = 0; j < vertices; j++)
        {
            if (graph[vertex][j] == 1 && !visited[j]) // If there is an edge and the vertex is not visited
            {
                visited[j] = 1;  // Mark the vertex as visited
                queue[rear++] = j;  // Enqueue the adjacent vertex
            }
        }
    }
}