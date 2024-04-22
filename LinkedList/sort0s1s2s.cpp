#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

ListNode *sort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // create three dummy nodes
    ListNode *zero_head = new ListNode(-1);
    ListNode *one_head = new ListNode(-1);
    ListNode *two_head = new ListNode(-1);

    // three pointers to the  dummy nodes
    ListNode *zero = zero_head;
    ListNode *one = one_head;
    ListNode *two = two_head;

    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (one_head->next) ? one_head->next : two_head->next;
    one->next = (two_head->next) ? two_head->next : two_head->next = NULL;

    ListNode *newHead = zero_head->next;
    return newHead;
}