#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
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