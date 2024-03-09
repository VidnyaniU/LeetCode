#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    // edge cases
    if (n == 1) // if there is only one element in the array
        return 0;
    if (nums[0] > nums[1]) // check if the first element is the peak
        return 0;
    if (nums[n - 1] > nums[n - 2]) // check if the last element is the peak
        return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] > nums[mid - 1]) // mid is on increasing path so peak lies on the rhs of mid
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int main()
{
    vector<int> nums = {1, 2};
    cout << findPeakElement(nums) << endl;
    return 0;
}