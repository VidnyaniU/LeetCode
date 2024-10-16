#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &arr, int target)
{

    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // Find complement (target - arr[i])
        int complement = target - arr[i];

        // If complement exists in the map, it means we found a pair
        if (freq.find(complement) != freq.end())
        {
            count += freq[complement]; // Add the frequency of complement
        }

        // Add the current element to the frequency map
        freq[arr[i]]++;
    }

    return count;
}
