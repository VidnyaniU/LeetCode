#include <bits/stdc++.h>
#include "linkedList.hpp"

int main()
{
    ListNode ll(2);
    // Node *head = new Node(2); // object of node
    // cout << head->data << " " << head->next << endl;

    // int cnt = 0;

    // convert array to linked list
    vector<int> arr = {2, 4, 5, 6};
    ListNode *head = ll.convertArrToLL(arr);

    // traverse the linkedlist
    // Node *temp = head; // DO NOT TAMPER THE HEAD
    // while (temp)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    //     cnt++;
    // }
    // cout << endl
    //      << "Length of the Linked List :: " << cnt << endl;

    // Node *newHead = deleteFromHead(head);
    // cout << newHead->data << endl;

    // head = deleteFromTail(head);
    // head = deleteK(head, 3);
    head = ll.insertAtHead(head, 100);
    head = ll.insertAtTail(head, 200);
    head = ll.insertAtK(head, 150, 4);
    ll.printLL(head);

    return 0;
}