#include <bits/stdc++.h>
using namespace std;
// Kth Missing Positive Number
// brute (linear search)
int findKthPositiveBrute(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }
    return k;
}
// optimised (binary search approach)
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + k;
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositiveBrute(arr, k) << endl;
    cout << findKthPositive(arr, k) << endl;

    return 0;
}