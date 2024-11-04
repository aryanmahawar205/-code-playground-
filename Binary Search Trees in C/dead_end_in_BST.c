// check if BST contains a dead end
// dead end means kya aapke paas koi aisa leaf node hain jisme aap kisi aur node ko attach nahi kar sakte

// to solve this problem, har ek leaf node ki possible ranges nikalni hain
// then subtract those ranges (high-low) and if the result is 1, then it means koi attachment nahi ho sakta and that is your dead end node

// question specified that all nodes in this tree should have values from 0 to INT_MAX

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value);
struct Node* insertNode(struct Node* root, int target);
bool isDeadEndBST(struct Node* root, int low, int high);

int main()
{
    int arr[] = {20, 15, 22, 10, 18, 21, 26};
    
    struct Node* root = NULL;
    
    for (int i = 0; i < 7; i++)
        root = insertNode(root, arr[i]);
        
    if (isDeadEndBST(root, 0, INT_MAX))
        printf("Yes, the BST has a dead end node.");
    
    else
        printf("No, there is not such deadend node in the BST.");
    
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

bool isDeadEndBST(struct Node* root, int low, int high)
{
    // bhai agar root hi nahi hain, then vo deadend nahi hain right...so return false
    // base case
    if (root == NULL)
        return false;
        
    // leaf node pe pahuch chuke ho, abh check karo ki kya vo dead end hain ya phir nahi
    if (root->left == NULL && root->right == NULL)
        if (root->data-low == 1 && high-root->data == 1)
            return true;
        else
            return false;
        
    // ya tho left jao and waha se return ya phir same story for right side
    return (isDeadEndBST(root->left, low, root->data) || isDeadEndBST(root->right, root->data, high));
}