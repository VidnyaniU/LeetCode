#include <bits/stdc++.h>
using namespace std;
// find the longest subarray with sum k (contains all positives)
int longestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    long long sum = nums[0];
    int left = 0, right = 0, maxLen = 0;

    while (right < n)
    {
        // trim from left side if the sum exceeds
        while (left <= right && sum > k)
        {
            sum -= nums[left];
            left++;
        }

        // get the  maximum length if the sum is equal
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        // find sum of the subarray
        if (right < n)
        {
            sum += nums[right];
        }
    }

    return maxLen;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int k = 6;
    cout << longestSubarray(nums, k);

    return 0;
}