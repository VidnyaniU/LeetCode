#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    string result = "";
    int size1 = word1.size();
    int size2 = word2.size();
    int i = 0;
    while (i < size1 || i < size2)
    {
        if (i < size1)
        {
            result += word1[i];
        }
        if (i < size2)
        {
            result += word2[i];
        }
        i++;
    }
    return result;
}
int main()
{
    string word1 = "abc";
    string word2 = "pqr";
    cout << mergeAlternately(word1, word2);
    return 0;
}
