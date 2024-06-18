#include "binaryTree.hpp"
using namespace std;
Node ::Node(int val)
{
    data = val;
    left = right = NULL;
}
void Node ::preorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
void Node ::inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void Node ::postorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}