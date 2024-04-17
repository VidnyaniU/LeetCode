#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// Naive approach
ListNode *midLL(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;
    int midListNode = (cnt / 2) + 1;
    while (temp != NULL)
    {
        midListNode = midListNode - 1;
        if (midListNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
// Tortoise-Hare approach
ListNode *middleListNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}