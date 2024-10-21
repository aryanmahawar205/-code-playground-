#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create();
void levelOrderTraversal(struct node *root);

struct node* queue[100];
int rear = -1;
int front = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    
    else
        return false;
}

bool isFull()
{
    if (rear == 100-1)
        return true;
    
    else
        return false;
}

void enqueue(struct node* value)
{
    if (isFull())
        return;
    
    else if(isEmpty())
        rear = front = 0;
    
    else
        rear++;
    
    queue[rear] = value;
}

struct node* dequeue()
{
    struct node* x;
    if (isEmpty())
        return NULL;
    
    else if(front == rear)
    {
        x = queue[front];
        front = rear = -1;
    }
    
    else
    {
        x = queue[front];
        front++;
    }
    
    return x;
}
int main()
{
    struct node *root;
    root = NULL;
    root = create();

    printf("Level Order Traversal of the Binary Tree is as follows - ");
    levelOrderTraversal(root);

    return 0;
}

struct node *create()
{
    struct node *newNode;
    int x;

    newNode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter data (-1 for no more nodes) - ");
    scanf("%d", &x);

    if (x == -1)
    {
        free(newNode); // Free memory if no node is created
        return NULL;
    }
    
    else
    {
        newNode->data = x;
        printf("Enter left child of %d:\n", x);
        newNode->left = create();
        printf("Enter right child of %d:\n", x);
        newNode->right = create();
        return newNode;
    }
}

// Perform Level Order Traversal
void levelOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;
        
    else
    {
        enqueue(root);
        
        while(!isEmpty())
        {
            struct node *currentNode = dequeue();
            printf("%d ", currentNode->data);
            
            if(currentNode->left != NULL)
                enqueue(currentNode->left);
            
            if (currentNode->right != NULL)
                enqueue(currentNode->right);
        }
    }
}