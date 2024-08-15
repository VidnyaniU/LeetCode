#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];

        if (sum == k)
            ans++;

        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
                ans++;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k) << endl;

    return 0;
}