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
int main()
{

    return 0;
}