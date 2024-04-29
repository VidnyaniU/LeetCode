#include <bits/stdc++.h>
using namespace std;
class MinStack
{

    // stack<pair<int, int>> st;  //brute force approach

    stack<int> st; // optimised
    int mini;

public:
    MinStack()
    {
        mini = INT_MAX;
    }

    // void push(int val)
    // {
    //     int mini = INT_MAX;
    //     if (st.empty())
    //     {
    //         mini = val;
    //     }
    //     else
    //     {
    //         mini = min(st.top().second, val);
    //     }
    //     st.push({val, mini});
    // }
    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    void pop()
    {
        if (st.empty())
            return;

        int res = st.top();
        st.pop();
        if (res < mini)
        {
            mini = 2 * mini - res;
        }
    }

    int top()
    {
        if (st.empty())
            return;
        int res = st.top();
        if (res < mini)
            return mini;
        return res;
    }

    int getMin()
    {
        return mini;
    }
};
