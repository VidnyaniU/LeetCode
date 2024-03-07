#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums, int target, int size)
{
    int ans = size; // hypothetical answer
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            ans = mid; // may be the answer
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {3, 5, 7, 8, 10};
    int numsLen = nums.size();
    int target = 10;
    cout << lowerBound(nums, target, numsLen);
    return 0;
}