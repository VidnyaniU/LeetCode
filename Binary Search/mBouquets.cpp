#include <bits/stdc++.h>
using namespace std;

// isPossible function
bool isPossible(vector<int> &bloomDay, int days, int m, int k)
{
    int counter = 0, noOfBouquets = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= days)
        {
            counter++;
        }
        else
        {
            noOfBouquets += counter / m;
            counter = 0;
        }
    }
    noOfBouquets += counter / m;

    return noOfBouquets >= m;
}

// brute force approach
int minDaysBrute(vector<int> &bloomDay, int m, int k)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    // impossible case
    if (m * k > bloomDay.size())
    {
        return -1;
    }

    for (int i = mini; i <= maxi; i++)
    {
        if (isPossible(bloomDay, i, m, k))
            return i;
    }

    return -1;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    long long val = m * k;
    if (val > bloomDay.size())
        return -1;

    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        low = min(low, bloomDay[i]);
        high = max(high, bloomDay[i]);
    }

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(bloomDay, mid, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}
int main()
{
    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    // cout << minDaysBrute(bloomDay, m, k) << endl;
    cout << minDays(bloomDay, m, k) << endl;

    return 0;
}