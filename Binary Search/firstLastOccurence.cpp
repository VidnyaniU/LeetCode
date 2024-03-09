#include <bits/stdc++.h>
using namespace std;
// Find First and Last Position of Element in Sorted Array

// bruteforce
vector<int> searchRangeBrute(vector<int> &nums, int target)
{

    vector<int> ans;
    int first = -1, last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
            {
                first = i;
            }
            last = i;
        }
    }
    ans.push_back(first);
    ans.push_back(last);

    return ans;
}

// using upper and lower bound
vector<int> searchRange(vector<int> &nums, int target);

// using plain binary search
vector<int> searchRange(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {2, 4, 6, 8, 8, 8, 11, 13};
    vector<int> ans = searchRangeBrute(nums, 8);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}