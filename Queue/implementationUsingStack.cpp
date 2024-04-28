#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> S1;
    stack<int> S2;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
        }
        S1.push(x);
        while (!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
    }

    int pop()
    {
        int res = S1.top();
        S1.pop();
        return res;
    }

    int peek()
    {
        int res = S1.top();
        return res;
    }

    bool empty()
    {
        return S1.empty();
    }
};
int main()
{

    return 0;
}