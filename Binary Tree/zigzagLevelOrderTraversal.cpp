#include "binaryTree.hpp"
using namespace std;
vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;
    queue<Node *> nodesQ;
    nodesQ.push(root);

    bool leftToRight = true;
    while (!nodesQ.empty())
    {
        int size = nodesQ.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *node = nodesQ.front();
            nodesQ.pop();

            int index = leftToRight ? i : (size - 1 - i);
            row[index] = node->data;

            if (node->left)
                nodesQ.push(node->left);
            if (node->right)
                nodesQ.push(node->right);
        }

        leftToRight = !leftToRight;
        result.push_back(row);
    }

    return result;
}
int main()
{

    return 0;
}