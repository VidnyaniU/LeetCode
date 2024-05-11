#include <bits/stdc++.h>
using namespace std;
string reverse(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }

    return s;
}
int main()
{
    string s = "garfield";
    string ans2 = reverse(s);
    cout << ans2;

    return 0;
}