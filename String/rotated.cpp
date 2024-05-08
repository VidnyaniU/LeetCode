#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;
    else
    {
        string temp = s + s;
        if (temp.find(goal) == -1)
            return false;
        else
            return true;
    }
}
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    cout << rotateString(s, goal);

    return 0;
}