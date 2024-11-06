// adjacency list representation for undirected unweighted graph

#include <stdio.h>
#include <stdlib.h>

#define maxNode 4

// for the LL
struct Node
{
    int data;
    struct Node *next;
};

// to create the head which will be a pointer to the LL
struct List
{
    struct Node* head;
};

void addNode(int s, int d);
void printList();

// but we need to create am array of head lists to hold all vertices
struct List *adjList[maxNode] = {0};

int main()
{
    // create an array of head nodes
    for (int i = 0; i < maxNode; i++)
    {
        adjList[i] = (struct List*)malloc(sizeof(struct List));
        adjList[i]->head = NULL;
    }
    
    // passing a pair of vertices, where you want an edge
    addNode(0, 1);
    addNode(0, 3);
    addNode(1, 2);
    
    // function to print list
    printf("Adjacency List created successfully as...\n\n");
    printList();
    
    return 0;
}

void addNode(int s, int d)
{
    struct Node *dest, *temp, *src;
    
    // DRY RUN!
    if (adjList[s]->head == NULL)
    {
        src = (struct Node*)malloc(sizeof(struct Node));
        src->data = s;
        src->next = NULL;
        adjList[s]->head = src;
    }
    
    dest = (struct Node*)malloc(sizeof(struct Node));
    dest->data = d;
    dest->next = NULL;
    temp = adjList[s]->head;
    
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = dest;
}

void printList()
{
    for (int i = 0; i < maxNode; i++)
    {
        struct Node *p = adjList[i]->head;
        printf("Adjacency List for vertex %d -> ", i);

        if (p == NULL)
            printf("No adjacent vertices.\n");
            
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
                printf("%d ", p->data);
            }
            printf("\n");
        }
    }
}
