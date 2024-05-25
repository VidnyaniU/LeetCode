#include <bits/stdc++.h>
using namespace std;

// using stack
string removeDuplicatesSt(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (st.empty() || st.top() != ch)
            st.push(ch);
        else
            st.pop();
    }
    string str;
    while (!st.empty())
    {
        str = st.top() + str;
        st.pop();
    }
    return str;
}

string removeDuplicates(string s)
{
    string ans = "";
    int index = 0;
    while (index < s.length())
    {
        if (ans.length() > 0 && ans[ans.length() - 1] == s[index])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[index]);
        }

        index++;
    }

    return ans;
}
int main()
{
    string s = "abbaca";
    cout << removeDuplicatesSt(s) << endl;

    cout << removeDuplicates(s) << endl;
    return 0;
}