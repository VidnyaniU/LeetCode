#include <bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int> &gain)
{
    int max = 0;
    int alt = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        alt = alt + gain[i];
        if (alt > max)
            max = alt;
    }
    return max;
}
int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};
    cout << largestAltitude(gain);

    return 0;
}