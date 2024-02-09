// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }
        }
        for (int i = 0; i < index; i++)
        {
            cout << nums[i] << " ";
        }

        return index;
    }
};
int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }

    Solution s1;
    s1.removeElement(nums, 2);
    return 0;
}
