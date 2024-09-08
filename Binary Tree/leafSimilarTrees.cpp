#include "binaryTree.hpp"

using namespace std;

bool leafSimilar(Node *root1, Node *root2)
{
    vector<int> leaf1;
    vector<int> leaf2;

    preorder(root1, leaf1);
    preorder(root2, leaf2);
    return leaf1 == leaf2;
}

