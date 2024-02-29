#include <bits/stdc++.h>
using namespace std;
// Find longest subarray with sum k (contains positives and negatives)
// using prefix sum

int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        // sum is k update maxlen
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        // calculate x-k
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // finally update the map
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
int main()
{
    vector<int> nums = {-1, 1, 1};
    int k = 1;
    cout << longestSubarray(nums, k);
    return 0;
}