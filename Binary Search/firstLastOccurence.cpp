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

// using plain binary search
// two times binary search for both first and last

int firstOccur(vector<int> &nums, int target, int n)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first;
}
int lastOccur(vector<int> &nums, int target, int n)
{
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = firstOccur(nums, target, n);
    int last = lastOccur(nums, target, n);

    return {first, last};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    // vector<int> ans = searchRangeBrute(nums, 8);
    vector<int> ans = searchRange(nums, 8);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}