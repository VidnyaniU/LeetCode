#include <bits/stdc++.h>
using namespace std;

// Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str.
// If more than one character occurs the maximum number of time then print the lexicographically smaller characte
char maxOccurring(string s)
{
    char ans = ' ';
    int max = INT_MIN;
    int cnt = 0;
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        for (int i = 0; i <= end; i++)
        {
            if (s[start] == s[i])
            {
                cnt++;
            }
        }
        if (cnt >= max && s[start] < ans)
        {
            max = cnt;
            ans = s[start];
        }
        start++;
    }

    return ans;
}
int main()
{
    string s = "bunn";
    cout << maxOccurring(s);
    return 0;
}