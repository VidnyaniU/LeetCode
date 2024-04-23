#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// Add 1 to a number represented by LL
// input :: 1->5->9->NULL
// output :: 1->6->0->NULL

// iterative approach
ListNode *reverseLLRecur(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseLLRecur(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
ListNode *add1(ListNode *head)
{
    head = reverseLLRecur(head);
    ListNode *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if (carry == 1)
    {
        ListNode *newNode = new ListNode(1);
        head = reverseLLRecur(head);
        newNode->next = head;
        return newNode;
    }

    head = reverseLLRecur(head);
    return head;
}
// recursive approach
int helper(ListNode *head)
{
    ListNode *temp = head;
    int carry;
    if (temp == NULL)
        return 1;
    carry = helper(temp->next);
    temp->data = temp->data + carry;

    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}

ListNode *add1Recur(ListNode *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        ListNode *newNode = new ListNode(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}