#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

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
// naive approach
bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = temp->next;
    while (temp != NULL)
    {
        if (st.top() != temp->data)
            return false;
        temp = temp->next;
        st.pop();
    }

    return true;
}

// Tortoise-Hare method
bool isPalindromeTH(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true; // edge case
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseLLRecur(slow->next); // reverse the second half

    // use two pointers to compare
    ListNode *first = head;
    ListNode *second = newHead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseLLRecur(newHead); // reverse back to original
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLLRecur(newHead); // reverse back to original
    return true;
}