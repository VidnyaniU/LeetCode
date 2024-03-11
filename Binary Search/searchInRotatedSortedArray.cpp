// Search in Rotated Sorted Array (distinct elements)
#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;

        // check if left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target <= nums[mid]) // check if target lies in between

                high = mid - 1;
            else

                low = mid + 1; // eliminate left half if not
        }

        // check if the right half is sorted
        else
        {
            // check if target lies in between
            if (nums[mid] <= target && target <= nums[high])

                low = mid + 1;
            else
                high = mid - 1; // eliminate right half if not
        }
    }

    return -1;
}
int main()
{
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4};
    int target = 2;
    cout << search(nums, target);

    return 0;
}