// detect cycle in a directed graph using DFS

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// define the graph and path array globally
int graph[MAX][MAX], path[MAX], vertices;

bool detectCycle(int start);
bool isCycle();

int main()
{
    printf("Enter the number of vertices in the graph - "); scanf("%d", &vertices);
    
    printf("\nEnter the adjacency matrix...\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);
    }
    
    for (int i = 0; i < vertices; i++)
        path[i] = 0;
    
    if (isCycle())
        printf("\nThere is a cycle in the graph!");
    
    else
        printf("\nNo, there is no cycle in tbe graph!");
    
    return 0;
}

bool detectCycle(int start)
{
    // mark the current vertex as visited(in DFS path)
    path[start] = 1;
    
    // recur for all the vertices adjacent to the current vertex
    for (int j = 0; j < vertices; j++)
    {
        // if there is an edge and the adjacent node is in the current path, its a cycle
        if (graph[start][j] == 1)
        {
            if (path[j] == 1) // node is already in currnet path
                return true;
            
            if (path[j] == 0 && detectCycle(j)) // if not visited, recurse deeper
                return true;
        }
    }
    
    // after exploring all adjacent nodes, mark the current vertex as unvisited
    path[start] = 0;
    
    return false;
}

// function to initiate DFS for cycle detection
bool isCycle()
{
    for (int i = 0; i < vertices; i++)
    {
        if (path[i] == 0) // start DFS from each unvisited node
        {
            if (detectCycle(i))
                return true;
        }
    }
    
    return false;
}