#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    int sz1 = s.length();
    int sz2 = t.length();
    int i = 0, j = 0, count = 0;

    if (sz1 > sz2)
        return false;
    while (i < sz1 && j < sz2)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
            count++;
        }
        else
            j++;
    }
    return count == sz1;
}
int main()
{
    cout << isSubsequence("axc", "ahbgdc");
    return 0;
}