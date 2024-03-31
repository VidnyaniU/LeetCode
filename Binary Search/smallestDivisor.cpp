#include <bits/stdc++.h>
using namespace std;
// Find the Smallest Divisor Given a Threshold
int sumFunc(vector<int> &nums, int div)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += ceil((double)nums[i] / (double)div);
    }
    return sum;
}
// brute force
int smallestDivisorBrute(vector<int> &nums, int threshold)
{
    int maxi = *max_element(nums.begin(), nums.end());

    for (int d = 1; d <= maxi; d++)
    {

        if (sumFunc(nums, d) <= threshold)
        {
            return d;
        }
    }

    return -1;
}
// optimized

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    if (n > threshold)
        return -1;
    int low = 1, high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (sumFunc(nums, mid) <= threshold)
        {
            high = mid - 1; // eliminate  rt half
        }
        else
        {
            low = mid + 1; // eliminate left half
        }
    }

    return low;
}
int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << smallestDivisor(nums, threshold);

    return 0;
}