#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, max_len = 0, len, zeroes = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
            zeroes++;
        if (zeroes > k)
        {
            if (nums[l] == 0)
                zeroes--;
            l++;
        }
        if (zeroes <= k)
        {
            len = r - l + 1;
            max_len = max(len, max_len);
        }
        r++;
    }

    return max_len;
}
int main()
{
    vector<int> nums = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << longestOnes(nums, k);
    return 0;
}