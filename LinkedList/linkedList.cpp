#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
    }
};

int main()
{
    Node *head = new Node(2); // object of node
    cout << head->data << " " << head->next << endl;

    delete head;
    return 0;
}