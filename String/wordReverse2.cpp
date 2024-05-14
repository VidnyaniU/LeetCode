#include <bits/stdc++.h>
using namespace std;
// input : s = " My name is Bunbun "
// output: "yM eman si nubnuB"
string wordRev2(string s)
{
    int len = s.length();
    stringstream ss(s);
    vector<string> strvec;
    string temp;
    while (ss >> temp)
    {
        strvec.push_back(temp);
    }
    string ans;
    for (int i = 0; i < strvec.size(); i++)
    {
        int start = 0;
        int end = strvec[i].size() - 1;
        string word = strvec[i];
        while (start < end)
        {
            swap(word[start++], word[end--]);
        }
        ans += word + " ";
    }

    return ans;
}
int main()
{
    string s = " My name is Bunbun ";
    string ans = wordRev2(s);

    cout << ans;
    return 0;
}