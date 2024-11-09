// detect cycle in undirected graph using DFS

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Define the graph and visited array globally
int graph[MAX][MAX], visited[MAX], vertices;

bool detectCycle(int start, int parent);
bool isCycle();

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
    
    if (isCycle())
        printf("\nThere is a cycle in the graph!");
    
    else
        printf("\nNo there in no cycle in the graph!");

    return 0;
}

bool detectCycle(int start, int parent)
{
    // Mark the current vertex as visited
    visited[start] = 1;

    // Recur for all the vertices adjacent to the current vertex
    for (int j = 0; j < vertices; j++)
    {
        // Check if there's an edge from start to j
        if (graph[start][j] == 1)  // Only check when there's an edge
        {
            // If the neighbor is not visited, recurse
            if (!visited[j])
            {
                if (detectCycle(j, start))
                    return true;
            }
            // If the neighbor is visited and not the parent, cycle is found
            else if (j != parent)
                return true;
        }
    }
    
    return false;
}

// Function to initiate DFS for cycle detection
bool isCycle()
{
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])  // Start DFS from each unvisited node
        {
            if (detectCycle(i, -1))  // Parent of the initial node is -1
                return true;
        }
    }
    
    return false;
}