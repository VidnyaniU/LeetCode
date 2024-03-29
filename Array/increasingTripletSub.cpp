#include <bits/stdc++.h>
using namespace std;
bool increasingTriplet(vector<int> &nums)
{
    int x = INT_MAX, y = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= x)
            x = nums[i];
        if (nums[i] > x && nums[i] <= y)
            y = nums[i];
        if (nums[i] > x && nums[i] > y)
            return true;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << increasingTriplet(nums);

    return 0;
}