#include <bits/stdc++.h>
using namespace std;
string decodeString(string s)
{
    int n = s.size();
    int count = 0;
    int repeat = 0;

    stack<string> str;
    stack<int> nums;

    string current = "";

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
            count = count * 10 + (s[i] - '0');
        else if (isalpha(s[i]))
            current = current + s[i];

        if (s[i] == '[')
        {
            nums.push(count);
            str.push(current);
            current = "";
            count = 0;
        }

        if (s[i] == ']')
        {
            repeat = nums.top();
            nums.pop();
            string temp = current;
            for (int i = 1; i < repeat; i++)
            {
                current += temp;
            }
            if (!str.empty())
            {
                current = str.top() + current;
            }
            str.pop();
        }
    }
    return current;
}
