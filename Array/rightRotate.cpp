#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    return 0;
}