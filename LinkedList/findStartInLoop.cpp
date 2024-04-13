#include <bits/stdc++.h>
using namespace std;
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

// Naive approach using map
Node *findStart(Node *head)
{
    Node *temp = head;
    map<Node *, int> mpp;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;
        mpp[temp] = 1;
        temp = temp->next;
    }

    return NULL;
}
// Optimised approach using Tortoise-Hare method
Node *findStartTH(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head; // resetting slow to head
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow; // or fast
        }
    }
    return NULL;
}