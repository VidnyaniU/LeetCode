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
// optimised
Node *segregate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next; // save it for later use

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead; // last odd node point to first even node
    return head;
}