#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    // using two Queues
    queue<int> Q1, Q2;
    void push2Qs(int x)
    {
        Q2.push(x);
        while (!Q1.empty())
        {
            Q2.push(Q1.front());
            Q1.pop();
        }
        // swap
        queue<int> temp = Q1;
        Q1 = Q2;
        Q2 = Q1;
    }
    // using one Queue
    queue<int> Q;

    void push(int x)
    {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }

    int pop()
    {
        int result = Q.front();
        Q.pop();
        return result;
        ;
    }

    int top()
    {
        return Q.front();
    }

    bool empty()
    {
        return Q.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(3);
    obj->push(4);
    obj->push(2);
    obj->push(1);
    obj->pop();

    return 0;
}