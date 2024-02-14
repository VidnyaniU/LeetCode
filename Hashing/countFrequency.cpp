// You are given an array 'arr' of length 'n' containing integers within the range '1' to 'x'.
// Your task is to count the frequency of all elements from 1 to n.
// Return a frequency array as an array in the function such that index 0 represents the frequency of 1,
//  index 1 represents the frequency of 2, and so on.

#include <bits/stdc++.h>
using namespace std;
void countFrequency(int n, int x, int nums[])
{
    map<int, int> mapp;
    for (int i = 0; i < n; i++)
    {
        mapp[nums[i]]++;
    }
    for (auto x : mapp)
    {
        cout << x.first << " occurs " << x.second << " times." << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n = 6;
    int x = 9;
    int nums[x] = {1, 4, 2, 1, 3, 6};

    countFrequency(n, x, nums);

    return 0;
}
