#include <bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2)
{
    if (str1 + str2 != str2 + str1)
        return "";
    else
        return str1.substr(0, gcd(str1.size(), str2.size()));
}
int main()
{
    string str1 = "ABABAB";
    string str2 = "ABAB";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}