#include <bits/stdc++.h>
using namespace std;
int minDifference(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 4)
        return 0; // we can make all the numbers equal

    sort(nums.begin(), nums.end());

    int k = nums.size() - 3;
    int ans = nums.back() - nums[0];
    for (int i = k - 1; i < nums.size(); i++)
    {
        ans = min(ans, nums[i] - nums[i - k + 1]);
    }

    return ans;
}
