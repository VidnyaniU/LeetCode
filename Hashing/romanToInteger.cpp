#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    vector<int> ans;
    unordered_map<string, int> mpp;
    mpp["I"] = 1;
    mpp["V"] = 5;
    mpp["X"] = 10;
    mpp["L"] = 50;
    mpp["C"] = 100;
    mpp["D"] = 500;
    mpp["M"] = 1000;
    mpp["IV"] = 4;
    mpp["IX"] = 9;
    mpp["XL"] = 40;
    mpp["XC"] = 90;
    mpp["CD"] = 400;
    mpp["CM"] = 900;

    int a = 0, len = s.length();
    for (int i = 0; i < len; ++i)
    {
        string t2(1, s[i]);

        if (i != len - 1)
            t2 += s[i + 1]; // concatenating next symbol
        if (i != len - 1 && (mpp.find(t2) != mpp.end()))
        {
            a += mpp[t2]; // we found the corresponding match of the concatenated symbols in the table
            i++;
        }
        else
        {
            string t1(1, s[i]); // consider single string only
            a += mpp[t1];
        }
    }

    return a;
}
int main()
{
    cout << romanToInt("XII");
    return 0;
}