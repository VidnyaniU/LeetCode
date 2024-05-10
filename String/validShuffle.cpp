#include <bits/stdc++.h>
using namespace std;
bool validShuffle(string s1, string s2, string shuffle)
{
    int n1 = s1.size();
    int n2 = s2.size();
    int n = shuffle.size();

    // if the length of sum of n1 and n2 is not same as shuffle length then its not a valid shuffle
    if (n != n1 + n2)
        return false;

    // storing the frequency of each character in a hash map
    unordered_map<char, int> freq;

    // for s1
    for (int i = 0; i < n1; i++)
        freq[s1[i]]++;

    // for s2
    for (int i = 0; i < n2; i++)
        freq[s2[i]]++;

    // if any character from the hash map is not present in the shuffle return false
    for (int i = 0; i < n; i++)
    {
        if (freq.find(shuffle[i]) != freq.end())
            freq[shuffle[i]]--;
        else
            return false;
    }

    // check if all the frequencies in the map are 0
    for (auto it : freq)
        if (it.second != 0)
            return false;

    return true;
}
int main()
{
    string s1 = "XY";
    string s2 = "12";
    string shuffle = "XY21";
    cout << validShuffle(s1, s2, shuffle) << endl;
    return 0;
}