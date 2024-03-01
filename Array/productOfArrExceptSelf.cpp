#include <bits/stdc++.h>
using namespace std;
// Product of Array Except Self
// brute force
vector<int> productExceptSelfBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int mul = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            mul *= nums[j];
        }
        ans.push_back(mul);
    }

    return ans;
}
// usingp prefix and postfix
vector<int> productExceptSelf(vector<int> &nums)
{

    int n = nums.size();
    vector<int> pmul(n);
    vector<int> posmul(n);
    vector<int> ans(n);
    pmul[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pmul[i] = pmul[i - 1] * nums[i - 1];
    }
    posmul[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--)
    {
        posmul[j] = posmul[j + 1] * nums[j + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = pmul[i] * posmul[i];
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    // vector<int> ans = productExceptSelfBrute(nums);
    vector<int> ans = productExceptSelf(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}