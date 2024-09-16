#include "binaryTree.hpp"
using namespace std;
Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    Node *right_child = root->right;
    Node *last_right = findLastRight(root->left);
    last_right->right = right_child;
    return root->left;
}

Node *findLastRight(Node *root)
{
    if (root->right == NULL)
        return root;
    return findLastRight(root->right);
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return helper(root);

    Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}