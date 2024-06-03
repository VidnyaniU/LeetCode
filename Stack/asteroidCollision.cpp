#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    for (auto i : asteroids)
    {
        if (st.empty())
            st.push(i);
        else if (i > 0)
            st.push(i);

        else if (i < 0)
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(i))
                st.pop();

            if (!st.empty() && st.top() > 0)
            {
                if (st.top() == abs(i))
                {
                    st.pop();
                }
            }
            else
            {
                st.push(i);
            }
        }
    }
    vector<int> ans;
    for (; !st.empty();)
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
