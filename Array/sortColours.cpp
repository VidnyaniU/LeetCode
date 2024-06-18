#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &nums, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[minInd])
            {
                minInd = j;
            }
        }
        // swapping
        if (minInd != i)
        {
            swap(nums[minInd], nums[i]);
        }
    }
}

void sortColors(vector<int> &nums)
{
    selectionSort(nums, nums.size());
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }

    return 0;
}