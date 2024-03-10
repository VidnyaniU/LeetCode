#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int rightSum = accumulate(nums.begin(), nums.end(), 0); // sum all the elements

    int leftSum = 0;

    for (int i = 0; i < n; i++)
    {
        rightSum = rightSum - nums[i]; // trimming right sum from left
        if (rightSum == leftSum)
        {
            return i;
        }
        leftSum = leftSum + nums[i]; // adding to leftSum
    }
    return -1;
}
int main()
{
    vector<int> nums = {2, 1, -1};
    cout << pivotIndex(nums);
    return 0;
}