#include <bits/stdc++.h>
using namespace std;

// Find the number that appears once, and the other numbers twice

// brute force
int singleNumberBrute(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        int num = nums[i];
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == num)
            {
                count++;
            }
        }
        if (count == 1)
        {
            return nums[i];
        }
    }
    return -1;
}
// better approach using hash
int singleNumberHash(vector<int> &nums)
{
    int maxi = nums[0];
    // find the maximum element in the array to define hash size
    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(nums[i], maxi);
    }

    // declare hash
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }

    // find the single element
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash[nums[i]] == 1)
        {
            return nums[i];
        }
    }

    return -1;
}
// better approach using map
int singleNumberMap(vector<int> &nums)
{
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }

    return -1;
}
// optimal
int singleNumberOptimal(vector<int> &nums)
{
    int XOR = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        XOR = XOR ^ nums[i];
    }
    return XOR;
}
int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
    // cout << singleNumberBrute(nums);
    // cout << singleNumberHash(nums);
    // cout << singleNumberMap(nums);
    cout << singleNumberOptimal(nums);
    return 0;
}