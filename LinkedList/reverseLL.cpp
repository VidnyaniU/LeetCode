#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// using stack

ListNode *reverseLLStack(ListNode *head)
{
    stack<int> st;
    ListNode *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}
// iterative approach
ListNode *reverseLLIter(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}
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