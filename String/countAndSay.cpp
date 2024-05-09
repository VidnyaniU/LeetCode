#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    // base condition
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        string temp = "";
        s = s + "$"; // adding a delimitter
        int cnt = 1;

        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j - 1])
            {
                temp = temp + to_string(cnt);
                temp = temp + s[j - 1];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        s = temp;
    }
    return s;
}
int main()
{
    int n = 4;
    cout << countAndSay(n);

    return 0;
}