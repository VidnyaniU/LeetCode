#include <bits/stdc++.h>
using namespace std;
class StackArr
{
public:
    int ptr = -1;
    int n = 5; // size of array
    // vector<int> stack_arr;
    int *stack_arr = new int(n);
    void push(int x)
    {
        if (ptr > n)
            cout << "Stack Overflow!" << endl;
        else
        {
            ptr = ptr + 1;
            stack_arr[ptr] = x;
        }
    }
    int top()
    {
        if (ptr == -1)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }

        return stack_arr[ptr];
    }
    int pop()
    {
        if (ptr == -1)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        ptr--;
        return stack_arr[ptr + 1];
    }
    int size()
    {
        return ptr + 1; /* code */
    }
    bool isEmpty()
    {
        if (ptr == -1)
            return 1;
        else
            return 0;
    }
};
int main()
{
    StackArr st;
    st.push(2);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}
