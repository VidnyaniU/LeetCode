#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    double maxSum = 0;
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    maxSum = sum;
    int start = 0, end = k;

    while (end < nums.size())
    {
        sum += nums[end];
        sum -= nums[start];
        start++;
        end++;
        maxSum = max(sum, maxSum);
    }
    return maxSum / k;
}
int main()
{
    vector<int> nums = {0, 4, 0, 3, 2};
    cout << findMaxAverage(nums, 1);
    return 0;
}