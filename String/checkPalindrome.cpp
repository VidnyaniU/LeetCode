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

bool isPalindrome(string s1)
{
    if (s1 == reverse(s1))
        return true;

    return false;
}
int main()
{
    string s = "abcba";
    cout << isPalindrome(s) << endl;

    return 0;
}