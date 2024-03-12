// find minimum element in rotated sorted array
#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        nums[mid] > nums[end] ? start = mid + 1 : end = mid;
    }
    return nums[start];
}
int main()
{
    vector<int> nums = {3, 1, 2, 3, 3, 3, 3};
    cout << findMin(nums);
    return 0;
}