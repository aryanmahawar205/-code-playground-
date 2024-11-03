// kth largest element in BST

// an effective approach to this problem would be to use the inorder ka ulta karna
// instead of doing left, root, right we could do right, root, left to get reverse inorder
// this will be in descending order
// from this descending order use the counter of k and find kth largest

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
void kthLargestElement(struct Node* root, int* ans, int* k);

int main()
{
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);
    
    int ans = 0; int k = 3;
    
    kthLargestElement(root, &ans, &k);
    
    printf("The kth (here 3rd) largest element in the BST is - %d", ans);
    
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

void kthLargestElement(struct Node* root, int* ans, int* k)
{
    if (root == NULL)
        return;
        
    // go right, as reverse inorder
    kthLargestElement(root->right, ans, k);
    
    // decrement k as one of the largest (infact the largest of all) has been visited
    (*k)--;
    
    // check if that is what you want to give as answer
    if ((*k) == 0)
        *ans = root->data;
    
    if ((*k) <= 0)
        return;
    
    // if not, check the left side (again because yaha pe ham reverse inorder kar rahe hain)
    kthLargestElement(root->left, ans, k);
}