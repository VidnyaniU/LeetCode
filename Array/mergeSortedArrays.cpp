// Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include <iostream>
#include <vector>
using namespace std;
class MergeSortedArrays
{
public:
    void merge(int nums1[], int m, int nums2[], int n)
    {
        int i = m - 1;
        int j = n - 1;
        int last = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums2[j] > nums1[i])
            {
                nums1[last] = nums2[j];
                j--;
                last--;
            }
            else
            {
                nums1[last] = nums1[i];
                i--;
                last--;
            }
        }

        // copying remaining elements of nums2 to nums1
        while (j >= 0)
        {
            nums1[last] = nums2[j];
            j--;
            last--;
        }
    }
};
int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m = 3;
    int n = 3;

    MergeSortedArrays m1;
    m1.merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << endl;
    }

    return 0;
}
