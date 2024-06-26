#include <bits/stdc++.h>
using namespace std;
/*You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1
*/
int minKBitFlips(vector<int> &nums, int k)
{
    int n = nums.size(), flipped = 0, res = 0;
    vector<int> isFlipped(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
            flipped ^= isFlipped[i - k];
        if (flipped == nums[i])
        {
            if (i + k > n)
                return -1;
            isFlipped[i] = 1;
            flipped ^= 1;
            res++;
        }
    }

    return res;
}
int main()
{
    vector<int> nums = {0, 1, 0};
    int k = 1;
    cout << minKBitFlips(nums, k);
    return 0;
}