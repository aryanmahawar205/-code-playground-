// BFS IMPLEMENTATION

#include <stdio.h>

#define MAX 10

// Define the graph and visited array globally
int graph[MAX][MAX], visited[MAX], vertices;
int queue[MAX], front = -1, rear = -1; // Queue for BFS

void enqueue(int vertex);
int dequeue();
int isEmpty();
void BFS(int start);

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
    
    // Perform BFS starting from vertex 0
    printf("\nThe BFS traversal of the graph is: ");
    BFS(0);
    
    return 0;
}

void enqueue(int vertex)
{
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0; // First element in the queue
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue()
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int dequeuedValue = queue[front];
        front++;
        if (front > rear) { // Reset the queue when empty
            front = rear = -1;
        }
        return dequeuedValue;
    }
}

int isEmpty()
{
    return front == -1;
}

void BFS(int start)
{
    // Mark the start node as visited
    visited[start] = 1;
    enqueue(start);
    
    while (!isEmpty())
    {
        // Dequeue a vertex and print it
        int current = dequeue();
        printf("%d ", current);
        
        // Enqueue all adjacent vertices that are unvisited
        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark it as visited
                enqueue(i);  // Add to the queue for future exploration
            }
        }
    }
}