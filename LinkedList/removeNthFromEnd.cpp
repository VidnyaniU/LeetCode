#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

ListNode *removeNBrute(ListNode *head, int n)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    // edge case when N is same as length
    if (cnt == n)
    {
        ListNode *newHead = head->next;
        delete (head);
        return newHead;
    }

    int res = n - cnt;
    temp = head;

    // to get previous node
    while (temp != NULL)
    {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }
    ListNode *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

// Optimised approach
ListNode *removeN(ListNode *head, int n)
{
    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *fast = temp;
    ListNode *slow = temp;

    for (int i = 1; i <= n; i++)
        fast = fast->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return temp->next;
}
}