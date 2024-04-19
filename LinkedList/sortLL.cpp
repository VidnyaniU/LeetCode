#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;
ListNode *merge(ListNode *left_head, ListNode *right_head)
{
    ListNode *dummyNode = new ListNode(0);
    ListNode *temp = dummyNode;
    while (left_head != NULL && right_head != NULL)
    {
        if (left_head->data <= right_head->data)
        {
            temp->next = left_head;
            // temp = left_head;
            left_head = left_head->next;
        }
        else
        {
            temp->next = right_head;
            // temp = right_head;
            right_head = right_head->next;
        }
        temp = temp->next;
    }

    if (left_head)
    {
        temp->next = left_head;
        left_head = left_head->next;
    }
    else
    {
        temp->next = right_head;
        right_head = right_head->next;
    }
    return dummyNode->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = NULL;

    // finding mid
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = NULL; // breaking the ll in two halves

    ListNode *left_head = sortList(head);
    ListNode *right_head = sortList(slow);

    return merge(left_head, right_head);
}