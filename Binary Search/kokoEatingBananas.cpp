
#include <bits/stdc++.h>
using namespace std;
// return the minimum integer k such that koko can eat all bananas within h hours
int maxi(vector<int> &piles)
{
    int maxim = piles[0];
    for (int i = 0; i < piles.size(); i++)
    {
        if (maxim <= piles[i])
        {
            maxim = piles[i];
        }
    }
    return maxim;
}
double totalHrs(vector<int> &piles, int hourly)
{
    double tothrs = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        tothrs += ceil((double)(piles[i]) / (double)(hourly));
    }
    return tothrs;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = maxi(piles);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        double reqTime = totalHrs(piles, mid);
        if (reqTime <= h)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}