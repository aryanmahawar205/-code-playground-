#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create();
void inOrderTraversal(struct node *root);

int main()
{
    struct node *root;
    root = NULL;
    root = create();

    printf("Inorder Traversal of the Binary Tree is as follows - ");
    inOrderTraversal(root);

    return 0;
}

struct node *create()
{
    struct node *newNode;
    int x;

    newNode = (struct node *)malloc(sizeof(struct node));
    
    printf("Enter data (-1 for no more nodes) - ");
    scanf("%d", &x);

    if (x == -1)
    {
        free(newNode); // Free memory if no node is created
        return NULL;
    }
    
    else
    {
        newNode->data = x;
        printf("Enter left child of %d:\n", x);
        newNode->left = create();
        printf("Enter right child of %d:\n", x);
        newNode->right = create();
        return newNode;
    }
}

// left Root Right
void inOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;
        
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}