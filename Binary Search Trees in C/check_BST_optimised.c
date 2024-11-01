// given a binary tree, check if it is a BST

// optimised solution - using previous pointer reference

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data);
struct Node* createBinaryTreeUsingLevelOrder(int arr[], struct Node* root, int i, int n);
void inOrderTraversal(struct Node* root);
bool isBST(struct Node* root, int* previous);

int main() {
    int arr[] = {4, 5, 10, 7, 8, 1}; // Example array (not a BST)
    struct Node* root = NULL;
    root = createBinaryTreeUsingLevelOrder(arr, root, 0, sizeof(arr) / sizeof(arr[0]));

    printf("Binary Tree created successfully with Inorder traversal - ");
    inOrderTraversal(root);
    printf("\n");
    
    int previous = INT_MIN;

    if (isBST(root, &previous))
        printf("Yes, the binary tree is a BST");
    
    else
        printf("No, the binary tree is not a BST");

    return 0;
}

bool isBST(struct Node* root, int* previous)
{
    // base case, remember kar yaar...last mai pahuchega like leaf node, tho can we say ki BST nahi hain?? no right, thats why return true
    if (root == NULL)
        return true;
        
    // checking left subtree
    bool left = isBST(root->left, previous);
    if (left == false)
        return false;
    
    // condition of inorder in BST violated here
    // as in like previous >= current...not possible in BST
    if (*previous >= root->data)
        return false;
        
    // update previous before checking right subtree and returning
    *previous = root->data;
    
    return isBST(root->right, previous);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

struct Node* createBinaryTreeUsingLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = newNode(arr[i]);
        root = temp;
        root->left = createBinaryTreeUsingLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = createBinaryTreeUsingLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}