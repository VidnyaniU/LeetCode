#include <bits/stdc++.h>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
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

    return false;
}

int main()
{
    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    cout << search(nums, 1);
    return 0;
}