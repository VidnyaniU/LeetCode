#include <bits/stdc++.h>
using namespace std;
bool isArraySpecial(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] % 2 == nums[i + 1] % 2)
            return false;
    }
    return true;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << isArraySpecial(nums);
    return 0;
}