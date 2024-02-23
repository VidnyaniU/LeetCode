#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    int size = s.size();
    stringstream ss(s);
    vector<string> strVec;

    string temp;
    while (ss >> temp)
    {
        strVec.push_back(temp);
    }
    string ans;
    // reverse for loop
    for (int i = strVec.size() - 1; i >= 1; i--)
    {
        ans += strVec[i] + " ";
    }
    ans += strVec[0]; // explicitly putting the first element

    return ans;
}
int main()
{
    string s = " Hello  World ";
    string ans = reverseWords(s);
    cout << ans;
    return 0;
}