#include <bits/stdc++.h>
using namespace std;

// single element which occurs only once and others twice in a sorted array
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0]; // if the array has single element

    // edge cases
    if (nums[0] != nums[1])
        return nums[0]; // for first element
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1]; // for last element

    // from 1st index ot n-2th index
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
            return nums[mid];

        // if we are standing at left half
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << singleNonDuplicate(nums);
    return 0;
}