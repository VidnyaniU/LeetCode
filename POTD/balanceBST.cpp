#include "../binaryTree.hpp"
using namespace std;

vector<int> arr;
void inorderTraversal(Node *root)
{
    if (root)
    {
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
}

Node *buildTree(int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildTree(start, mid - 1);
    root->right = buildTree(mid + 1, end);
    return root;
}
Node *balanceBST(Node *root)
{
    inorderTraversal(root);
    return buildTree(0, arr.size() - 1);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(NULL);
    root->right = new Node(2);
    root->right->left = new Node(NULL);
    root->right->right = new Node(3);
    root->right->right->left = new Node(NULL);
    root->right->right->right = new Node(4);
    root->right->right->right->left = new Node(NULL);
    root->right->right->right->right = new Node(NULL);

    Node *balancedBSTRoot = balanceBST(root);
    cout << balancedBSTRoot->data << endl;

    return 0;
}