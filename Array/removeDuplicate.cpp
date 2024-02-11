// Remove duplicate from sorted array
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(int nums[5])
    {

        int count = 0;
        for (int i = 0; i < 5; i++)
        {
            if (i < 5 - 1 && nums[i] == nums[i + 1])
            {
                continue;
            }
            else
            {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
int main()
{

    int nums[] = {1, 2, 2, 3, 3};

    Solution s1;
    cout << s1.removeDuplicates(nums) << endl;

    return 0;
}
