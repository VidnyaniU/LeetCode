#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    // using array
    int hashh[10] = {0};
    for (int i = 0; i < n; i++)
    {
        hashh[arr[i]] += 1; // this will increase the number of that particular index
    }
    //array can only store numbers till 10^6 in main and 10^7 in global so we use map for larger numbers

    // using map
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // number of queries
    int q;
    cout << "Enter the number of queries:";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "Enter the number you want to find the frequency of:";
        cin >> number;
        // fetch
        cout << "Using array: " << hashh[number] << endl;
        cout << "Using map: " << mpp[number] << endl;
    }

    return 0;
}
