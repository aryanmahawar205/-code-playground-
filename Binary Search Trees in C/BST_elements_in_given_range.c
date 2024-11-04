// print BST elements in a given range (in a sorted order)

// three step process to solve this problem optimally
// take the two numbers and check with every node starting from root node
// if the node being checked is bigger than both the given range limits, obviously go left
// if the node being checked is smaller than both the given range limits, obviously go right
// third case would be that the node being checked lies in the given range...perform left root right (INORDER TRAVERSAL) keeping in mind the check for range
// this will give the answer in sorted order

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int queue[25] = {0};
int rear = -1;
int front = -1;

struct Node
{
    int data;
    struct Node *left, *right;
};

bool isEmpty();
bool isFull();
void enqueue(int value);
int dequeue();
struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void rangeElementsOfBST(struct Node* root, int lower, int higher);

int main()
{
    int arr[] = {100, 200, 180, 300, 85, 90, 30, 20, 70, 68, 74, 65, 72, 81};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 14; i++)
        root = insertNode(root, arr[i]);
    
    int lower = 60; int higher = 80;
    
    rangeElementsOfBST(root, lower, higher);
    
    // Print elements in sorted order
    for (int i = 0; i < 14; i++) {
        printf("%d ", dequeue());
    }
    
    return 0;
}

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    
        return false;
}

bool isFull()
{
    if (rear == 13) // rear == size(queue)-1
        return true;
    
    return false;
}

void enqueue(int value)
{
    if (isFull())
        return;
    
    else if (isEmpty())
        rear = front = 0;
        
    else
        rear++;
    
    queue[rear] = value;
}

int dequeue()
{
    int x;
    
    if (isEmpty())
        return 0;
    
    else if (front == rear)
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

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int target)
{
    // base case
    if (root == NULL)
    {
        struct Node* temp = createNode(target);
        return temp;
    }
    
    // left side check
    if (target < root->data)
        root->left = insertNode(root->left, target);
    
    // right side check
    else
        root->right = insertNode(root->right, target);
    
    return root;
}

void rangeElementsOfBST(struct Node* root, int lower, int higher) {
    if (root == NULL)
        return;

    // If the current node's value is greater than the lower limit,
    // there might be values in the left subtree
    if (root->data > lower)
        rangeElementsOfBST(root->left, lower, higher);

    // If the current node's value is within the range, add it to the stack
    if (root->data >= lower && root->data <= higher)
        enqueue(root->data);

    // If the current node's value is less than the higher limit,
    // there might be values in the right subtree
    if (root->data < higher)
        rangeElementsOfBST(root->right, lower, higher);
}