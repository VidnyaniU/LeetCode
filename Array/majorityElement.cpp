#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second > (nums.size() / 2))
            {
                return it.first;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);

    Solution s1;
    cout<<s1.majorityElement(nums)<<endl;

    return 0;
}
