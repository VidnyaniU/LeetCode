#include "linkedList.hpp"
using namespace std;
ListNode *mergeNodes(ListNode *head)
{
    ListNode *curr = head->next;
    while (curr)
    {
        if (curr->next->data != 0)
        {
            // add
            curr->data += curr->next->data;
            // delete the next node
            curr->next = curr->next->next;
        }
        else
        {
            // delete next node with val 0
            curr->next = curr->next->next;
            curr = curr->next;
        }
    }
    return head->next;
}
