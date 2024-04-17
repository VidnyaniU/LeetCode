#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// Naive approach using map
bool detectLoopMap(ListNode *head)
{
    ListNode *temp = head;
    map<ListNode *, int> mpp;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
            return true;
        mpp[temp] = 1;
        temp = temp->next;
    }

    return false;
}
// Optimised approach using Tortoise-Hare method
bool detectLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}