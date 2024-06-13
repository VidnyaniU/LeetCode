#include "linkedList.hpp"
using namespace std;
// find second middle
ListNode *getMid(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // cout << slow->data << endl;
    return slow;
}
// reverse ll
ListNode *reverseLL(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}
int pairSum(ListNode *head)
{

    ListNode *temp = head;
    ListNode *mid = getMid(head);

    // reverse other half
    ListNode *head2 = reverseLL(mid);

    int maxi = INT_MIN;
    int sum = 0;

    while (head2 != NULL)
    {
        sum = temp->data + head2->data;
        if (sum > maxi)
        {
            maxi = sum;
        }
        sum = 0;
        temp = temp->next;
        head2 = head2->next;
    }

    return maxi;
}
// int main()
// {
//     ListNode ll(0);
//     // convert array to linked list
//     vector<int> arr = {4, 2, 1, 3};
//     ListNode *head = ll.convertArrToLL(arr);
//     ll.printLL(head);

//     cout << "Maximum Twin Sum :: " << pairSum(head) << endl;
//     return 0;
// }