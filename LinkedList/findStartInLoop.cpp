#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// Naive approach using map
ListNode *findStart(ListNode *head)
{
    ListNode *temp = head;
    map<ListNode *, int> mpp;
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
ListNode *findStartTH(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
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