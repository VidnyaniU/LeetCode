#include <bits/stdc++.h>
using namespace std;
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
//  and removing all non-alphanumeric characters, it reads the same forward and backward.
//  Alphanumeric characters include letters and numbers.

// helper functions
bool isValidChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }

    return false;
}

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    char temp = ch - 'A' + 'a';
    return temp;
}
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

bool isValidPalindrome(string s)
{
    string temp = "";
    // remove non-alphanumeric characters
    for (int i = 0; i < s.size(); i++)
    {
        if (isValidChar(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    // to lower case
    for (int i = 0; i < temp.size(); i++)
    {
        temp[i] = toLowerCase(temp[i]);
    }

    // check palindrome or not
    return isPalindrome(temp);
}
int main()
{

    return 0;
}