#include <bits/stdc++.h>
using namespace std;

// rotate the array by one place
void rotateArrayByOnePLace(vector<int> &nums, int size)
{
    int temp = nums[0];
    for (int i = 1; i < size; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[size - 1] = temp;
}
// rotate the array by k places
// reverse function
void reverse(vector<int> &nums, int start, int end)
{
    while (start <= end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void leftRotateArrayBykPlaces(vector<int> &nums, int size, int k)
{

    // brute force approach
    /*
    int temp[k];
    // copying all the k elements
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[i];
    }

    // shifting all the leftover elements to the left
    for (int j = k; j < size; j++)
    {
        nums[j - k] = nums[j];
    }
    // copying the temp array elements

    for (int i = size - k; i < size; i++)
    {
        nums[i] = temp[i - (size - k)];
    }
*/
    // optimal approach

    // reverse from 0 to k-1
    // reverse(nums.begin(), nums.begin() + k);
    reverse(nums, 0, k - 1);

    // reverse from k to size-1
    // reverse(nums.begin() + k, nums.end());
    reverse(nums, k, size - 1);

    // reverse whole array
    // reverse(nums.begin(), nums.end());
    reverse(nums, 0, size - 1);
}

void rightRotateArrayBykPlaces(vector<int> &nums, int size, int k)
{
    //if k is multiple of size of array no rotation  
    if (k > size)
    {
        k = k % size;
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.begin() + k);
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int size = nums.size();
    // rotateArrayByOnePLace(nums, size);
    int k = 3;
    leftRotateArrayBykPlaces(nums, size, k);

    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    rightRotateArrayBykPlaces(nums, size, k);
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
