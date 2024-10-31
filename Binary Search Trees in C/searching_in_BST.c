// search for an element in BST
// TC - O(n)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
bool searchValue(struct Node* root, int value);

int main()
{
    int arr[] = {4, 2, 3, 6, 5, 7, 1};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
    {
        root = insertNode(root, arr[i]);
    }
    
    if (searchValue(root, 7))
        printf("Yes, 7 is present in the BST!\n");
    
    if(!searchValue(root, 98))
        printf("No, 98 is not present in the BST!");
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

bool searchValue(struct Node* root, int value)
{
    // base case 1 - value not found in tree
    if (root == NULL)
        return false;
    
    // base case 2 - at some point, value if found in tree
    if (root->data == value)
        return true;
    
    // search in the left side
    if (value < root->data)
        return searchValue(root->left, value);
    
    // search in the right side
    else
        return searchValue(root->right, value);
}