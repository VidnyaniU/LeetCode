#include <bits/stdc++.h>
using namespace std;

int maxSubArrayBrute(vector<int> &nums)
{
    long long maxi = INT_MIN;
    long long sum;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum += nums[k];

            if (sum > maxi)
                maxi = sum;
        }
    }
    return maxi;
}

int maxSubArrayBetter(vector<int> &nums)
{
    long long maxi = INT_MIN;
    long long sum;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];

            if (sum > maxi)
                maxi = sum;
        }
    }
    return maxi;
}
// kadane's algo
int maxSubArray(vector<int> &nums)
{
    long long maxi = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxi)
            maxi = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}
