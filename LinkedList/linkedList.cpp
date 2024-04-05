#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
    }
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }

    cout << "NULL" << endl;
}
Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head; // at first mover will point to head
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp; // in the first iteration head->next will point to arr[1] and so on
        mover = temp;       // mover will move with temp
    }

    return head;
}

// DELETION IN LL
Node *deleteFromHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head; // store current head in temp
    head = head->next; // move head to the next

    delete temp; // delete the previous head

    return head; // return new head
}

Node *deleteFromTail(Node *head)
{
    // if there is no element or only one element in the linked list
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;    // deleting the last node
    temp->next = nullptr; // pointing the second last node to NULL

    return head; // returns head
}
int main()
{
    // Node *head = new Node(2); // object of node
    // cout << head->data << " " << head->next << endl;

    // int cnt = 0;

    // convert array to linked list
    vector<int> arr = {2, 4, 5, 6};
    Node *head = convertArrToLL(arr);

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

    head = deleteFromTail(head);
    printLL(head);

    return 0;
}