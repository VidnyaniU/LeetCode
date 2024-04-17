#include <bits/stdc++.h>
#include "linkedList.hpp"
using namespace std;

ListNode ::ListNode(int data1, ListNode *next1)
{
    data = data1;
    next = next1;
}

ListNode::ListNode(int data1)
{
    data = data1;
}

void ListNode ::printLL(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }

    cout << "NULL" << endl;
}
ListNode *ListNode ::convertArrToLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head; // at first mover will point to head
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp; // in the first iteration head->next will point to arr[1] and so on
        mover = temp;       // mover will move with temp
    }

    return head;
}

// DELETION IN LL
ListNode *ListNode ::deleteFromHead(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *temp = head; // store current head in temp
    head = head->next;     // move head to the next

    delete temp; // delete the previous head

    return head; // return new head
}

ListNode *ListNode ::deleteFromTail(ListNode *head)
{
    // if there is no element or only one element in the linked list
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;    // deleting the last node
    temp->next = nullptr; // pointing the second last node to NULL

    return head; // returns head
}

ListNode *ListNode ::deleteK(ListNode *head, int k)
{
    // if the linked list is empty
    if (head == NULL)
        return head;
    // if we want to delete head
    if (k == 1)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    // to delete any node
    int cnt = 0;
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// remove if the value is passed
ListNode *ListNode ::deleteVal(ListNode *head, int val)
{
    // if the linked list is empty
    if (head == NULL)
        return head;
    // if we want to delete head
    if (head->data == val)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    // to delete any node
    ListNode *temp = head;
    ListNode *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// INSERTION IN LL
ListNode *ListNode ::insertAtHead(ListNode *head, int val)
{
    return new ListNode(val, head);
}

ListNode *ListNode ::insertAtTail(ListNode *head, int val)
{

    // ll in empty
    if (head == NULL)
        return new ListNode(val);

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(val);

    return head;
}

ListNode *ListNode ::insertAtK(ListNode *head, int val, int k)
{
    // case 1 : if ll is empty
    if (head == NULL)
    {
        if (k == 1)
            return new ListNode(val);
        else
            return NULL;
    }

    // case 2: if k =1
    if (k == 1)
        return new ListNode(val);

    // case 3: k = 2 to n+1
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            ListNode *newNode = new ListNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
