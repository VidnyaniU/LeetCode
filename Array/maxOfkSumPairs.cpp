#include <bits/stdc++.h>
using namespace std;
int maxOperations(vector<int> &nums, int k)
{
    int count = 0;
    int i = 0, j = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            count++;
            i++;
            j--;
        }
        else if (nums[i] + nums[j] < k)
            i++;
        else
            j--;
    }

    return count;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    cout << maxOperations(nums, k) << endl;

    return 0;
}