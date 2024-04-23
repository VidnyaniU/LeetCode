#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

ListNode *add2numbers(ListNode *head1, ListNode *head2)
{
    ListNode *t1 = head1;
    ListNode *t2 = head2;

    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    ListNode *newNode;
    int carry = 0;
    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
            sum = sum + t1->data;
        if (t2)
            sum = sum + t2->data;

        newNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }
    if (carry)
    {
        ListNode *node = new ListNode(carry);
        curr->next = node;
    }

    return dummyNode->next;
}