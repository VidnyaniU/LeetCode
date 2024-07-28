#include "linkedList.hpp"
using namespace std;
ListNode* removeElements(ListNode *head, int data)
{
    if (head==NULL)
        return head;
    head->next = removeElements(head->next, data);
    return head->data == data ? head->next : head;
}
