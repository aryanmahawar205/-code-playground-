// create a BST from an array
// in a BST, the inorder traversal of the tree gives a sorted array
// TC - O(n^2)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void inorderTraversal(struct Node* root);

int main()
{
    int arr[] = {4, 2, 3, 6, 5, 7, 1};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
    {
        root = insertNode(root, arr[i]);
    }
    
    printf("BST created! Here is the Inorder Traversal of it (should be sorted as it is a BST) - ");
    inorderTraversal(root);
}

void inorderTraversal(struct Node* root)
{
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
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