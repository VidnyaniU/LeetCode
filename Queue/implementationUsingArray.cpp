#include <bits/stdc++.h>
using namespace std;
class QueueArr
{
public:
    int n = 25; // queu of size 25
    int *queue_arr;
    int front, rear, currSize;
    QueueArr()
    {
        queue_arr = new int[n];
        front = -1;
        rear = -1;
        currSize = 0;
    }

    void push(int x)
    {
        if (currSize == n)
        {
            cout << "Queue is full!" << endl;
            exit(1);
        }
        if (rear == -1)
        {
            front = 0;
            rear = 0;
            queue_arr[rear] = x;
            currSize++;
        }

        else
        {
            rear = (rear + 1) % n; // circular array
            queue_arr[rear] = x;
            currSize++;
        }
    }
    int top()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            exit(1);
        }
        return queue_arr[front];
    }
    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            exit(1);
        }
        int popped = queue_arr[front];
        if (currSize == 1)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            front = (front + 1) % n;
        }
        currSize--;
        return popped;
    }
    int size()
    {
        return currSize;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void printQueue()
    {
        int i = 0;
        while (i < n)
        {
            cout << queue_arr[i++] << " ";
        }
        cout << endl;
    }
};
int main()
{
    QueueArr Q;
    Q.push(1);
    Q.push(9);
    Q.push(34);
    // Q.push(43);
    Q.pop();
    Q.push(43);

    Q.printQueue();
    return 0;
}