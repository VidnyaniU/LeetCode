#include <bits/stdc++.h>
using namespace std;
class ListNode
{

public:
    int data;
    ListNode *next;

    ListNode(int data1, ListNode *next1);

    ListNode(int data1);
    void printLL(ListNode *head);
    ListNode *convertArrToLL(vector<int> &arr);
    ListNode *deleteFromHead(ListNode *head);
    ListNode *deleteFromTail(ListNode *head);
    ListNode *deleteK(ListNode *head, int k);
    ListNode *deleteVal(ListNode *head, int val);
    ListNode *insertAtHead(ListNode *head, int val);
    ListNode *insertAtTail(ListNode *head, int val);
    ListNode *insertAtK(ListNode *head, int val, int k);
};