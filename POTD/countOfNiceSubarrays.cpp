#include <bits/stdc++.h>
using namespace std;
int numberOfSubarrays(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] %= 2;
    }

    vector<int> prefixCount(nums.size() + 1);
    prefixCount[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans += (sum >= k) ? prefixCount[sum - k] : 0;
        prefixCount[sum]++;
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k);
    return 0;
}