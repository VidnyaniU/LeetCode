#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;
// naive
ListNode *deleteMiddleN(ListNode *head)
{
    ListNode *temp = head;

    if (head == NULL || head->next == NULL)
        return NULL;

    // find length
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    temp = head;

    int res = len / 2;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            ListNode *delNode = temp->next;
            temp->next = temp->next->next;
            delete (delNode);
            break;
        }
        temp = temp->next;
    }

    return head;
}
// optimised
ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
    return head;
}
