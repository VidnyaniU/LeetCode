#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// Naive approach using map
int findLen(ListNode *head)
{
    ListNode *temp = head;
    int timer = 1;
    int value;
    map<ListNode *, int> mpp;
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
int fineLenTH(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
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