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
// Naive approach
Node *midLL(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;
    int midNode = (cnt / 2) + 1;
    while (temp != NULL)
    {
        midNode = midNode - 1;
        if (midNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
// Tortoise-Hare approach
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}