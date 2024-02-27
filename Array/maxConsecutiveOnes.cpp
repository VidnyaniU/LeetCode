#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxim = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            if (count > maxim)
            {
                maxim = count;
            }
        }
        else
        {
            count = 0;
        }
    }

    return maxim;
}
int main()
{

    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 0, 1};
    cout << findMaxConsecutiveOnes(nums);

    return 0;
}