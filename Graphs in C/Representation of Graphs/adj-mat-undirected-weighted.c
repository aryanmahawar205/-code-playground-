// implement a graph using adjacency matrix
// the graph is an undirected and weighted graph

#include <stdio.h>

int main()
{
    int vertex, edge; // vertex holds number of vertices and edges hold number of edges
    printf("Enter the number of vertices in the graph - "); scanf("%d", &vertex);
    printf("\nEnter the number of edges in the graph - "); scanf("%d", &edge);
    
    int adjMat[vertex][vertex]; // the adjacency matrix
    
    // initialize all elements of adjMat to 0
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            adjMat[i][j] = 0;
    }
    
    int u, v, weight; // these will be the variables showing edge relationships and corresponding weights (like u=0 & v=1 means between vertices 0 and 1, there is an edge)
    printf("\nEnter edge relationship and weight...\n");
    
    for (int i = 0; i < edge; i++)
    {
        scanf("%d %d %d", &u, &v, &weight);
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }
    
    // print the adjacency matrix
    printf("\nAdjacency matrix created successfully as...\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
            printf("%d ", adjMat[i][j]);
        printf("\n");
    }
    
    return 0;
}