#include <bits/stdc++.h>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int i = 0;
    int XOR1 = 0, XOR2 = 0;
    for (; i < nums.size()-1; i++)
    {
        XOR1 = XOR1 ^ nums[i];
    }
    for (i = 1; i <= nums.size(); i++)
    {
        XOR2 = XOR2 ^ i;
    }

    return XOR1 ^ XOR2;
}
int main()
{
    vector<int> nums = {1, 2, 4};
    cout << missingNumber(nums);
    return 0;
}