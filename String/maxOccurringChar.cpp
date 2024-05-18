#include <bits/stdc++.h>
using namespace std;

// Given a string s of alphabets. The task is to find the maximum occurring character in the string str.
// If more than one character occurs the maximum number of time then print the lexicographically smaller characte
char maxOccurring(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int num = 0;
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z')
        {
            num = ch - 'a';
        }
        else
        {
            num = ch - 'A';
        }
        arr[num]++;
    }
    // find maximum
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            ans = i;
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}
int main()
{
    string s = "bunn";
    cout << maxOccurring(s) << endl;
    return 0;
}