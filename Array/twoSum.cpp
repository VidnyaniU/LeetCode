#include <bits/stdc++.h>
using namespace std;

// two sum

// using hashmap T.C.: O(N*log N)
vector<int> twoSumHash(vector<int> &nums, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        int more = target - curr;
        if (mpp.find(more) != mpp.end())
        {

            return {mpp[more], i};
        }
        mpp[curr] = i;
    }

    return {-1, -1};
}

// two-pointer approach
vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
            return {left, right};
        else if (sum > target)
            right--;
        else
            left++;
    }

    return {-1, -1};
}
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSumHash(nums, target);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << ans[i] << endl; 
    }

    return 0;
}