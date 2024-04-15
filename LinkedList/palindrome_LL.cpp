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
Node *reverseLLRecur(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseLLRecur(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
// naive approach
bool isPalindrome(Node *head)
{
    Node *temp = head;
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
bool isPalindromeTH(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true; // edge case
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverseLLRecur(slow->next); // reverse the second half

    // use two pointers to compare
    Node *first = head;
    Node *second = newHead;

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