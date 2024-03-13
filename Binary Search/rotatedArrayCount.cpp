// find how many times the array has been rotated
#include <bits/stdc++.h>
using namespace std;
int rotationCountWithoutDuplicates(vector<int> &nums)
{
    int index = -1;
    int ans = INT_MAX;
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // for optimization
        if (nums[low] <= nums[high])
        {
            // ans = min(ans, nums[low]); // array is sorted
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }

        // if left half is sorted
        if (nums[low] <= nums[mid])
        {
            // ans = min(ans, nums[low]);
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }

            low = mid + 1;
        }

        else
        {
            // ans = min(ans, nums[mid]);
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}
int rotationCount(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        nums[mid] > nums[end] ? start = mid + 1 : end = mid;
    }
    return start;
}
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    // cout << rotationCountWithoutDuplicates(nums);
    cout << rotationCount(nums);
    return 0;
}