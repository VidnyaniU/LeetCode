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
int findLen(Node *head)
{
    Node *temp = head;
    int timer = 1;
    int value;
    map<Node *, int> mpp;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            value = mpp[temp];
            return (timer - value);
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }

    return 0;
}
// Optimised approach using Tortoise-Hare method
int fineLenTH(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    int cnt = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cnt = 1;
            fast = fast->next;
            while ((fast != slow))
            {
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
}