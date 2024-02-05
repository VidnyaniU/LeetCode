// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the combinations in any order.

// we follow the same process as generating subset
#include <iostream>
#include <vector>
using namespace std;

class combinationS
{
public:
    vector<vector<int>> ans;
    void help(vector<int> &candidates, int target, int i, int currSum, vector<int> temp)
    {
        // bounding condition
        if (currSum > target)
        {
            return;
        }
        // base case
        if (i == candidates.size())
        {
            if (currSum == target)
            {
                ans.push_back(temp);
            }
            return;
        }

        // inclusion
        currSum += candidates[i];
        temp.push_back(candidates[i]);
        help(candidates, target, i, currSum, temp);
        currSum -= candidates[i];
        temp.pop_back();

        // exclusion
        help(candidates, target, i + 1, currSum, temp);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        help(candidates, target, 0, 0, temp);
        return ans;
    }
};