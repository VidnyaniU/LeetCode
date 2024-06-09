#include <bits/stdc++.h>
using namespace std;
bool closeStrings(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;

    // storing frequency of each alphabet in the map
    map<char, int> mpp1;
    map<char, int> mpp2;
    vector<int> char_flag1(26), char_flag2(26), freq1, freq2;

    for (int i = 0; i < word1.length(); i++)
    {
        mpp1[word1[i]]++;
        char_flag1[word1[i] - 'a'] = 1; // checking the flag for each encountered alphabet
    }
    for (int i = 0; i < word2.length(); i++)
    {
        mpp2[word2[i]]++;
        char_flag2[word2[i] - 'a'] = 1; // checking the flag for each encountered alphabet
    }

    for (auto iter1 : mpp1)
    {

        freq1.push_back(iter1.second);
    }
    for (auto iter2 : mpp2)
    {
        freq2.push_back(iter2.second);
    }

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    if (freq1 != freq2)
        return false;
    if (char_flag1 != char_flag2)
        return false;

    return true;
}
int main()
{
    string word1 = "aacabb";
    string word2 = "bbcbaa";
    cout << closeStrings(word1, word2);
    return 0;
}