#include "linkedList.hpp"
using namespace std;
ListNode *front = nullptr, *rare = nullptr;
class QueueLL
{
public:
    int size = 0;
    bool empty()
    {
        return front == nullptr;
    }

    // inserting node at the end
    void enqueue(int data)
    {
        ListNode *temp = new ListNode(data);
        if (temp == nullptr)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            if (front == nullptr)
            {
                front = temp;
                rare = temp;
            }
            else
            {
                rare->next = temp;
                rare = temp;
            }
            cout << data << " inserted into queue" << endl;
            size++;
        }
    }
    // deleting from head
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << front->data << " removed from queue." << endl;
            ListNode *temp = front;
            front = temp->next;
            delete temp;
            size--;
        }
    }
    int peek()
    {
        return front->data;
    }
};