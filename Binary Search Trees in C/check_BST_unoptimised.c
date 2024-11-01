// given a binary tree, check if it is a BST

// unoptimised solution would be to use the property that the inorder traversal of a BST results in a sorted array
// this solution would take a TC - O(n) and SC - O(n)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data);
struct Node* createBinaryTreeUsingLevelOrder(int arr[], struct Node* root, int i, int n);
void inOrderTraversal(struct Node* root);
bool isBST(struct Node* root, int arr[], int* index);
bool isSorted(int arr[], int size);

int main() {
    int arr[] = {4, 5, 10, 7, 8, 1}; // Example array (not a BST)
    struct Node* root = NULL;
    root = createBinaryTreeUsingLevelOrder(arr, root, 0, sizeof(arr) / sizeof(arr[0]));

    printf("Binary Tree created successfully with Inorder traversal - ");
    inOrderTraversal(root);
    printf("\n");

    int size = sizeof(arr) / sizeof(arr[0]);
    int inorderArr[size]; // Array to hold in-order traversal values
    int index = 0; // Index for filling inorderArr

    // Populate inorderArr with in-order traversal values
    isBST(root, inorderArr, &index); 

    // Now check if the populated inorderArr is sorted
    if (isSorted(inorderArr, index)) {
        printf("The tree is a BST.\n");
    } else {
        printf("The tree is not a BST.\n");
    }

    return 0;
}

bool isBST(struct Node* root, int arr[], int* index) {
    if (root == NULL) {
        return true; // Base case: empty tree is a BST
    }

    // Traverse left subtree
    if (!isBST(root->left, arr, index)) {
        return false; // Left subtree not a BST
    }

    // Store current node's data in the array
    arr[(*index)++] = root->data;

    // Traverse right subtree
    return isBST(root->right, arr, index);
}

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false; // Found an element out of order
        }
    }
    return true; // All elements are in order
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
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