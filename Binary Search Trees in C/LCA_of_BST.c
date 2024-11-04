// least common ancestor (LCA) of a BST

// you will be given two nodes data from the BST and you have to return the value of the LCA of these two nodes

// an optimised way to solve this problem would be to use the concept of 'DIVERGENCE'

// in the tree example taken in this question (also in notebook), it the given two nodes are 20 and 40, the LCA = 30
// the approach is to start traversal from the root and check where we can find these two nodes, ie. to the left or to the right
// if both nodes are either to the left or to the right...then continue (it is not the LCA)
// but when we get a divergence or when one of the nodes is to the left and the other to the right, there we get our result of LCA

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
int findLCA(struct Node* root, int n1, int n2);

int main()
{
    int arr[] = {50, 18, 70, 10, 30, 65, 80, 28, 40, 20, 35, 45, 95};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 13; i++)
        root = insertNode(root, arr[i]);
        
    int n1 = 20; int n2 = 40; // given two nodes data jiska LCA hame nikalna hain
    
    int ans = findLCA(root, n1, n2);
    
    printf("The LCA of %d and %d is %d", n1, n2, ans);
    
    return 0;
}

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int target)
{
    // base case
    if (root == NULL)
    {
        struct Node* temp = createNode(target);
        return temp;
    }
    
    // left side check
    if (target < root->data)
        root->left = insertNode(root->left, target);
    
    // right side check
    else
        root->right = insertNode(root->right, target);
    
    return root;
}

int findLCA(struct Node* root, int n1, int n2)
{
    // 0 for no lCA, say tree is NULL, so what is the LCA we are trying to get??
    if (root == NULL)
        return 0;
        
    // lca lies somewhere in the left side, check there
    if (root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);
    
    // otherwise it lies in the right side, check there
    else if (root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);
        
    // if any of these conditions are not met, then just it means that DIVERGENCE has occured and we return the data of the diverging node, which is the required LCA
    else
        return root->data;
}