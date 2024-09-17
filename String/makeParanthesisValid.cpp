#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s)
{
    stack<char> st;
    int res = 0;
    for (auto i : s)
    {
        if (i == '(')
            st.push(i);
        else
        {
            if (!st.empty())
                st.pop();
            else
                res++;
        }
    }

    while (!st.empty())
    {
        st.pop();
        res++;
    }

    return res;
}
int main()
{
    string s ="(()";
    cout<<minAddToMakeValid(s);

    return 0;
}