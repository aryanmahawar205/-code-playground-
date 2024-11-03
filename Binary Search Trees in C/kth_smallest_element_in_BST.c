// kth smallest element in BST

// an effective approach to this problem would be to use the inorder traversal
// this will be in ascendnig order
// from this ascending order use the counter of k and find kth smallest

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void kthSmallestElement(struct Node* root, int* ans, int* k);

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);
    
    int ans = 0; int k = 3;
    
    kthSmallestElement(root, &ans, &k);
    
    printf("The kth (here 3rd) smallest element in the BST is - %d", ans);
    
    return 0;
}

struct Node* insertNode(struct Node* root, int target)
{
    // base case
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

void kthSmallestElement(struct Node* root, int* ans, int* k)
{
    if (root == NULL)
        return;
        
    // go left, as inorder traversal
    kthSmallestElement(root->left, ans, k);
    
    // decrement k as one of the smallest (infact the smallest of all) has been visited
    (*k)--;
    
    // check if that is what you want to give as answer
    if ((*k) == 0)
        *ans = root->data;
    
    if ((*k) <= 0)
        return;
    
    // if not, check the right side
    kthSmallestElement(root->right, ans, k);
}