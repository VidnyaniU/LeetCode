// Magnetic Force  Between two balls
// same as aggresive cows
#include <bits/stdc++.h>
using namespace std;
// helper function
bool canBePlaced(vector<int> &position, int mid, int m)
{
    int cntBalls = 1;
    int lastPos = position[0];
    for (int i = 0; i < position.size(); i++)
    {
        if (position[i] - lastPos >= mid)
        {
            cntBalls++;
            lastPos = position[i];
        }
        if (cntBalls >= m)
            return true;
    }
    return false;
}
int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int lo = 1, hi = (position[position.size() - 1] - position[0]) / (m - 1);
    int ans = 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (canBePlaced(position, mid, m))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}