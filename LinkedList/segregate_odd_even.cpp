#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// optimised
ListNode *segregate(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next; // save it for later use

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead; // last odd ListNode point to first even ListNode
    return head;
}