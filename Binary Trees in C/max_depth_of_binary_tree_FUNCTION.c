// max depth of a binary tree

// logic is to first recursively find the left hight and then the right height which given max sum of all nodes
// this is added to 1 and returned which will be the max depth of the binary tree

// FUNCTION BELOW

int maxDepth(Node* root)
{
    if (root == NULL)
        return 0;
    
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    
    return 1 + max(lh, rh);
}