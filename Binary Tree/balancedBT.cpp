#include "binaryTree.hpp"
using namespace std;
int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1)
        return false;
    if (isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}
