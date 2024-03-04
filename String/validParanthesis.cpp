#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' && st.top() != '(')
                return false;
            if (s[i] == '}' && st.top() != '{')
                return false;
            if (s[i] == ']' && st.top() != '[')
                return false;
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    cout << isValid("{[]}");
    return 0;
}