#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

// naive using hashing
ListNode *getIntersectionNodeHashing(ListNode *head1, ListNode *head2)
{
    map<ListNode *, int> mpp;
    ListNode *temp = head1;
    while (temp != NULL)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
            return temp;
        temp = temp->next;
    }
    return NULL;
}
// better
ListNode *collisionPoint(ListNode *headA, ListNode *headB, int d)
{
    while (d)
    {
        d--;
        headB = headB->next;
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
ListNode *getIntersectionNodeB(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA;
    ListNode *t2 = headB;
    int N1 = 0, N2 = 0;
    while (t1 != NULL)
    {
        N1++;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        N2++;
        t2 = t2->next;
    }
    if (N1 < N2)
    {
        return collisionPoint(headA, headB, N2 - N1);
    }
    else
        return collisionPoint(headB, headA, N1 - N2);
}
// optimised
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode *t1 = headA;
    ListNode *t2 = headB;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
        if (t1 == t2)
            return t1;
        if (t1 == NULL)
            t1 = headB;
        if (t2 == NULL)
            t2 = headA;
    }
    return t1;
}