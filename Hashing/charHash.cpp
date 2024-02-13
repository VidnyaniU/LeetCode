#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;

    // precompute
    // if specific letters we want we use 26 size along with the formula  else directly use arr of size 256 because at max we can have oonly 256 characters
    int hashh[26] = {0}; // here for small alphabets

    for (int i = 0; i < s.size(); i++)
    {
        hashh[s[i] - 'a'] += 1; // this will increase the number of that particular index
    }

    int char_hash[256] = {0}; // for all the characters
    for (int i = 0; i < s.size(); i++)
    {
        char_hash[s[i]] += 1; // this will increase the number of that particular index
    }
    // number of queries
    int q;
    cout << "Enter the number of queries:";
    cin >> q;
    while (q--)
    {
        char alphabet;
        cout << "Enter the character you want to find the frequency of:";
        cin >> alphabet;
        // fetch
        cout << "Using hashh[26]: " << hashh[alphabet - 'a'] << endl;
        cout << "Using char_hash[256]: " << char_hash[alphabet] << endl;
    }

    return 0;
}
