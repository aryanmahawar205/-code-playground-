// DFS IMPLEMENTATION

#include <stdio.h>

#define MAX 10

// Define the graph and visited array globally
int graph[MAX][MAX], visited[MAX], vertices;

void DFS(int start);

int main()
{
    // Input the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    
    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix:\n");
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
    
    // Perform DFS starting from vertex 0
    printf("\nThe DFS traversal of the graph is: ");
    DFS(0);
    
    return 0;
}

void DFS(int start)
{
    // Mark the current vertex as visited
    visited[start] = 1;
    printf("%d ", start);  // Print the current vertex
    
    // Recur for all the vertices adjacent to the current vertex
    for (int j = 0; j < vertices; j++)
    {
        if (graph[start][j] && !visited[j])  // If adjacent and not visited
        {
            DFS(j);  // Recurse to the adjacent vertex
        }
    }
}