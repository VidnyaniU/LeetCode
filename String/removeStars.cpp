#include <bits/stdc++.h>
using namespace std;

// Choose a star in s.
//  Remove the closest non-star character to its left, as well as remove the star itself.

string removeStars(string s)
{
    vector<char> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '*')
            ans.push_back(s[i]);
        else
            ans.pop_back();
    }
    s = "";
    for (int i = 0; i < ans.size(); i++)
    {
        s += ans[i];
    }
    return s;
}
int main()
{
    string s = "bun**bu*n";
    cout << removeStars(s) << endl;
    return 0;
}