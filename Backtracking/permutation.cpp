#include <iostream>
#include <vector>
using namespace std;

class Permutation
{
public:
    vector<vector<int>> ans;
    void help(vector<int> &nums, int i)
    {
        if (i == nums.size()) // base condition
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            help(nums, i + 1);
            // backtracking -going back to the normal state
            swap(nums[i], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        help(nums, 0);
        return ans;
    }
};