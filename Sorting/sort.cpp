#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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
                // swapping
                if (minInd != i)
                {
                    swap(nums[minInd], nums[i]);
                }
            }
        }
    }
}
void bubbleSort(vector<int> &nums, int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                didSwap = 1;
            }
        }
        // some optimization : if there is no swap done in the first iteration that means the array is already sorted.
        if (didSwap = 0)
        {
            break;
        }
    }
}
void insertionSort(vector<int> &nums, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            // left element is small
            swap(nums[j - 1], nums[j]);
            j--;
        }
    }
}
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> tempArr; // to store the elements temporarily
    int left = low;      // pointer to first subarray start
    int right = mid + 1; // pointer to second subarray start

    // comparing all the elements in both the subarrays for sorting
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            tempArr.push_back(nums[left]);
            left++;
        }
        else
        {
            tempArr.push_back(nums[right]);
            right++;
        }
    }

    // copying leftover elements from left subarray if any
    while (left <= mid)
    {
        tempArr.push_back(nums[left]);
        left++;
    }

    // copying leftover elements from right subarray if any
    while (right <= high)
    {
        tempArr.push_back(nums[right]);
        right++;
    }

    // copying all the elements back to the nums array
    for (int i = low; i <= high; i++)
    {
        nums[i] = tempArr[i - low];
    }
}
void mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);      // first half recursively
    mergeSort(nums, mid + 1, high); // second half recursively
    merge(nums, low, mid, high);    // compare and merge
}
int main()
{
    vector<int> nums = {2, 1, 7, 8, 5, 3, 9};

    // int n = sizeof(nums) / sizeof(nums[0]);
    int n = nums.size();
    cout << "Before Sorting: " << endl;
    display(nums, n);
    cout << "After Sorting: " << endl;
    mergeSort(nums, 0, n - 1);

    // selectionSort(nums, n);
    // bubbleSort(nums, n);
    // insertionSort(nums, n);
    display(nums, n);

    return 0;
}