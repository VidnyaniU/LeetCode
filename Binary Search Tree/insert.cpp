#include "binaryTree.hpp"
using namespace std;

Node *insertIntoBST(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val > root->data)
        root->right = insertIntoBST(root->right, val);
    else
        root->left = insertIntoBST(root->left, val);
    return root;
}