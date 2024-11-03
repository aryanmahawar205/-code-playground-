// sum of k smallest elements in a BST

// an inefficient approach would be to first traverse entire tree in inorder fashion and sum up the first K elements

// instead we could use the approach of inorder and simultaneously maintain the value of k which will act as a visited variable and decrement it as we reach a min node
// this efficient approach is been used to solve this problem here

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void sumOfKSmallestElements(struct Node* root, int* sum, int* k);

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);
    
    int sum = 0; int k = 3;
    
    sumOfKSmallestElements(root, &sum, &k);
    
    printf("The sum of K (here 3) smallest elements of the BST is - %d", sum);
    
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

void sumOfKSmallestElements(struct Node* root, int* sum, int* k)
{
    if (root == NULL)
        return;
    
    // first going left as per inorder to get the least number present in the BST
    sumOfKSmallestElements(root->left, sum, k);
    
    // decrement k as we have reached one of the min nodes
    (*k)--;
    
    if ((*k) >= 0)
        *sum += root->data;
        
    if ((*k) <= 0)
        return;
        
    // if not, ie. abhi tak k zero nahi hua, then just go check the right sub tree too
    sumOfKSmallestElements(root->right, sum, k);
}