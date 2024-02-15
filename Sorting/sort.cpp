#include <bits/stdc++.h>
using namespace std;

void display(int nums[], int n)
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
void selectionSort(int nums[], int n)
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

    display(nums, n);
}

int main()
{
    int nums[] = {2, 1, 7, 8, 5, 3, 9};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "Before Sorting: " << endl;
    display(nums, n);
    cout << "After Sorting: " << endl;

    selectionSort(nums, n);

    return 0;
}
