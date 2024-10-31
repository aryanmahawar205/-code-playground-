// deletion of node in BST
// TC - O(n)

// 3 cases

// CASE 1
// delete a leaf node - simply delete it and return NULL to previous node above it

// CASE 2
// delete a node which has only one child (left child) - delete it and return the address of the child node (left) to the previous node above it
// delete a node which has only one child (right child) - delete it and return the address of the child node (right) to the previous node above it

// IMPORTANT (CASE 3)
// delete a node which has both children - 
// left side se nikaloge then choose - BIGGEST VALUE
// right side se nikaloge then choose - SMALLLEST VALUE

// assume here we go with left side se nikalenge (ie. rightmost node in that subtree - BIGGEST VALUE)

// find the greatest element in left (say we call is child)

// if (parent != root)
// {
//      now uss child ke parent ke right ko bolo ki child ke left ko point karle
//      now, simply child->left = root->left aur child->right = root->right
//      finally delete the node and return the child
// }

// if (parent == root)
// {
//     child->right = root->right;
//     delete root;
//     return child;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
struct Node* deleteNode(struct Node* root, int target);
void inorderTraversal(struct Node* root);

int main()
{
    int arr[] = {20, 15, 50, 10, 40, 80, 45, 60, 90, 55, 85, 100, 52, 58, 95, 7, 12, 18, 11, 14, 3, 17, 19};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 23; i++)
    {
        root = insertNode(root, arr[i]);
    }
    
    printf("BST created! Here is the Inorder Traversal of it (should be sorted as it is a BST) - ");
    inorderTraversal(root);
    
    printf("\nHere is the Inorder Traversal of it after deleting node of value 45 (leaf node case) - ");
    root = deleteNode(root, 45);
    inorderTraversal(root);
    
    // printf("\nHere is the Inorder Traversal of it after deleting node of value 40 (node with one child - right child) - ");
    // root = deleteNode(root, 40);
    // inorderTraversal(root);
    
    // printf("\nHere is the Inorder Traversal of it after deleting node of value 100 (node with one chile - left child) - ");
    // root = deleteNode(root, 100);
    // inorderTraversal(root);
    
    // printf("\nHere is the Inorder Traversal of it after deleting node of value 15 (node with two childern - root != parent case) - ");
    // root = deleteNode(root, 15);
    // inorderTraversal(root);
    
    // printf("\nHere is the Inorder Traversal of it after deleting node of value 80 (node with two childern - root == parent case) - ");
    // root = deleteNode(root, 80);
    // inorderTraversal(root);
    
    // printf("\nHere is the Inorder Traversal of it after deleting node of value 999 (node does not exist in tree case) - ");
    // root = deleteNode(root, 999);
    // inorderTraversal(root);
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

struct Node* deleteNode(struct Node* root, int target)
{
    // base condition (element to be deleted cound not be found)
    if (root == NULL)
        return NULL;
        
    // now locate the element to be deleted first
    if (target < root->data)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (target > root->data)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }
        
    // perform actual deletion (3 cases)
    else
    {
        // delete a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL; // upar wale parent ko NULL return karna hain after deletion of a leaf node
        }
        
        // delete a node with a single child
        else if (root->right == NULL) // only left child exists
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL) // only right child exists
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        
        // delete a node having both children
        else
        {
            // find the greatest element from left
            struct Node* child = root->left;
            struct Node* parent = root;
            
            // rightmost node tak pahuchna hain to get largest element from left
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            
            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                free(root);
                return child;
            }
            
            else if (root == parent)
            {
                child->right = root->right;
                free(root);
                return child;
            }
        }
    }
}