// construct a binary tree from its level order traversal

// if we observe carefully, we can see that if the parent node is at index i in the array, 
// then the left chid is at index (2*i + 1) and the right child is at index (2*i + 2)

// we will insert the first element present in the array as the root node at level 0 in the tree and start traversing the array
// and for every node i we will insert both its childs left and right in the tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data);
struct Node* createBinaryTreeUsingLevelOrder(int arr[], struct Node* root, int i , int n);
void inOrderTraversal(struct Node* root);

int main()
{
    int arr[] = {4, 5, 10, 7, 8, 1};
    
    struct Node* root = NULL;
    
    root = createBinaryTreeUsingLevelOrder(arr, root, 0, 6);
    
    printf("Binary Tree created successfully with Inorder traversal - ");
    
    inOrderTraversal(root);
    
    return 0;
}

void inOrderTraversal(struct Node* root)
{
    if (root == NULL)
        return;
    
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* createBinaryTreeUsingLevelOrder(int arr[], struct Node* root, int i , int n)
{
    // base case
    if (i < n)
    {
        // create a node
        struct Node* temp = newNode(arr[i]);
        root = temp;
        
        // insert left child
        root->left = createBinaryTreeUsingLevelOrder(arr, root->left, 2 * i + 1, n);
        
        // insert right child
        root->right = createBinaryTreeUsingLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    
    return root;
}