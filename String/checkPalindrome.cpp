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

// using reverse
bool isPalindromeRev(string s)
{
    if (s == reverse(s))
        return true;

    return false;
}

// without using reverse
bool isPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
int main()
{
    string s = "abcba";
    cout << isPalindromeRev(s) << endl;
    cout << isPalindrome(s) << endl;

    return 0;
}