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
    vector<int> list1;
    vector<int> list2;
    ListNode *temp = head;
    ListNode *mid = getMid(head);

    // paste first half elements
    while (temp != mid)
    {
        list1.push_back(temp->data);
        temp = temp->next;
    }

    // reverse other half
    ListNode *head2 = reverseLL(mid);
    while (head2 != NULL)
    {
        list2.push_back(head2->data);
        head2 = head2->next;
    }

    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        sum = list1[i] + list2[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        sum = 0;
    }

    return maxi;
}
int main()
{
    ListNode ll(0);
    // convert array to linked list
    vector<int> arr = {4, 2, 1, 3};
    ListNode *head = ll.convertArrToLL(arr);
    ll.printLL(head);
    // ListNode *mid = getMid(head);
    // cout << "Mid is " << mid->data << endl;

    cout << "Maximum Twin Sum :: " << pairSum(head) << endl;
    return 0;
}