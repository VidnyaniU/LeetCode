#include "../binaryTree.hpp"
using namespace std;
int sum = 0;
void traverse(TreeNode *root)
{
    if (root)
    {
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
}


TreeNode *bstToGst(TreeNode *root)
{
    traverse(root);
    return root;
}
