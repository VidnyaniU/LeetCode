#include <bits/stdc++.h>
using namespace std;
string replaceS(string &s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }

        else
            ans.push_back(s[i]);
    }

    return ans;
}
int main()
{
    string s = "Banana ate Apple.";
    cout << replaceS(s);
    return 0;
}