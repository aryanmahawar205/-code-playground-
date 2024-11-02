// minimum distance between two nodes for a given binary tree
// we solve this problem using the concept of inorder traversal of BST and previous pointer concept

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void minimumNodeDistance(struct Node* root, int *previous, int *answer);
int min(int a, int b);

int main()
{
    int arr[] = {20, 10, 30, 2, 14, 25, 35};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
    {
        root = insertNode(root, arr[i]);
    }
    
    int previous = INT_MIN; int answer = INT_MAX;
    
    minimumNodeDistance(root, &previous, &answer);
    
    printf("The miminum distance between two nodes in the BST is - %d", answer);
    
    return 0;
}

void minimumNodeDistance(struct Node* root, int *previous, int *answer)
{
    if (root == NULL)
        return;
    
    minimumNodeDistance(root->left, previous, answer);
    
    // only calculate the distance if previous is not INT_MIN nahi tho it will lead to INTEGER OVERFLOW condition
    if (*previous != INT_MIN)
        *answer = min(*answer, root->data - *previous);
    
    *previous = root->data; // update previous to current node's data
    
    minimumNodeDistance(root->right, previous, answer);
}

int min(int a, int b)
{
    if (a < b)
        return a;
    
    return b;
}

struct Node* insertNode(struct Node* root, int target)
{
    // base case
    // jaise hi aapka root NULL banega, tumhe node create karni hain to insert
    if (root == NULL)
    {
        struct Node* temp = createNode(target);
        return temp;
    }
    
    // left side
    if (target < root->data)
        root->left = insertNode(root->left, target);
    
    // right side
    else
        root->right = insertNode(root->right, target);
    
    return root;
}

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}