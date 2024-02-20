// find second largest element in the array considering all elements are non-negatives
#include <bits/stdc++.h>
using namespace std;
// brute force approach
int secondLargestBruteForce(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int largest = arr[n - 1];
    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
// optimal solution
int secondLargest(vector<int> arr)
{
    int n = arr.size();
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}
int main()
{
    vector<int> arr = {2, 8, 5, 3, 2, 1, 9};
    cout << secondLargestBruteForce(arr) << endl;
    cout << secondLargest(arr) << endl;

    return 0;
}