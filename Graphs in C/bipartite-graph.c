// check if a graph is bipartite or not using DFS and two colour algorithm

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Define the graph and colour array globally
int graph[MAX][MAX], colour[MAX], vertices;

bool isBipartite(int start);

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

    // Initialize colour array to -1 (not coloured)
    for (int i = 0; i < vertices; i++)
        colour[i] = -1;

    // Before calling for the function, assign a colour to the starting vertex
    // Red = 0 and Blue = 1
    colour[0] = 0; // starting vertex being 0 is assigned Red colour before function call
    
    if (isBipartite(0))
        printf("\nThe graph is bipartite!\n");
    else
        printf("\nNo, the graph is not bipartite!\n");

    return 0;
}

bool isBipartite(int start)
{
    for (int j = 0; j < vertices; j++)
    {
        // If there is an edge between start and j
        if (graph[start][j] == 1)
        {
            // If the adjacent node has not been coloured
            if (colour[j] == -1)
            {
                // Assign the opposite colour to the adjacent vertex
                colour[j] = 1 - colour[start]; // Toggle between 0 and 1
                
                // Recursively check the adjacent node
                if (!isBipartite(j))
                    return false;
            }
            // If the adjacent node has the same colour, it's not bipartite
            else if (colour[j] == colour[start])
            {
                return false;
            }
        }
    }
    
    return true;
}