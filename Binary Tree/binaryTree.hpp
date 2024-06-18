#include <bits/stdc++.h>

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int val);
    void preorder(Node * root, vector <int> &ans);
    void inorder(Node * root , vector <int> &ans);
    void postorder(Node * root , vector <int>& ans);
};
