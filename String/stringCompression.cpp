#include <bits/stdc++.h>
using namespace std;
int compress(vector<char> &chars)
{
    int i = 0;
    int ansInd = 0;
    int n = chars.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        } // will come out of this loop if we reach end of chars or we encounter any new character

        // store the old character
        chars[ansInd++] = chars[i];

        int count = j - i;
        if (count > 1)
        {
            // convert count to string
            string cnt = to_string(count);
            for (auto ch : cnt)
            {
                chars[ansInd++] = ch;
            }
        }
        i = j;
    }
    return ansInd;
}

int main()
{
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('c');

    cout << compress(chars);
    return 0;
}