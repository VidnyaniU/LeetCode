#include <bits/stdc++.h>
using namespace std;

// iterative approach
int binaryIterative(vector<int> &nums, int target, int numsLen)
{
    int low = 0, high = numsLen - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1; // eliminate right half
        else
            low = mid + 1; // eliminate left half
    }

    return -1;
}
int binaryRecur(vector<int> &nums, int target, int numsLen, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)

        return -1;

    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        return binaryRecur(nums, target, numsLen, low, mid - 1);
    else
        return binaryRecur(nums, target, numsLen, mid + 1, high);
}
int main()
{
    vector<int> nums = {3, 5, 7, 8, 10};
    int numsLen = nums.size();
    int target = 10;
    // cout << binaryIterative(nums, target, numsLen);
    cout << binaryRecur(nums, target, numsLen, 0, numsLen - 1);

    return 0;
}