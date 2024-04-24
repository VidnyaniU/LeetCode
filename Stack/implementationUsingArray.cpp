#include <bits/stdc++.h>
using namespace std;
class StackArr
{
public:
    int top = -1;
    vector<int> stack_arr;
    void push(int x)
    {
        stack_arr[++top] = x;
    }
    int top()
    {
        return stack_arr[top];
    }
    int pop()
    {
        top--;
        return stack_arr[top + 1];
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};
