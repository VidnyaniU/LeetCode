#include <bits/stdc++.h>
using namespace std;
// Capacity To Ship Packages Within D Days

int daysReqd(vector<int> &weights, int cap)
{
    int days = 1, load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > cap)
        {
            days = days + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
// brute force using linear  search
int shipWithinDaysBrute(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    for (int cap = low; cap <= high; cap++)
    {
        int daysReq = daysReqd(weights, cap);
        if (daysReq <= days)
        {
            return daysReq;
        }
    }

    return -1;
}
// optimised approach using binary search
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (daysReqd(weights, mid) <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(weights, days) << endl;
    return 0;
}