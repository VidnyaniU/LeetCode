#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums, int size)
{
    int i = 0, j = 0;

    while (i < size)
    {
        if (nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
        i++;
    }

    for (; j < size; j++)
    {
        nums[j] = 0;
    }
}
int main()
{
    vector<int> nums = {1, 0, 3, 0, 5};
    int size = nums.size();

    cout << "Before moving zeroes: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    moveZeroes(nums, size);
    cout << "After moving zeroes: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}