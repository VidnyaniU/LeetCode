// find how many times the array has been rotated
#include <bits/stdc++.h>
using namespace std;

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
    cout << rotationCount(nums);
    return 0;
}