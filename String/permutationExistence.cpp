#include <bits/stdc++.h>
using namespace std;
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{

    // store character count
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traversal using window
    int i = 0;
    int window = s1.length();
    int count2[26] = {0};

    // running for first window
    while (i < window && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
        return true;

    // processing next windows
    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - window];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        if (checkEqual(count1, count2))
            return true;
    }

    return false;
}
int main()
{
    string s1 = "ba";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1, s2);
    return 0;
}