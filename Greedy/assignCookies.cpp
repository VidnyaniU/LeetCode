#include <bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int> &g, vector<int> &s)
{
    int n = g.size();

    int m = s.size();

    // Sort the greed factors in ascending
    // order to try and satisfy the
    // least greedy children first
    sort(g.begin(), g.end());

    // Sort the cookie sizes in ascending
    // order to use the smallest cookies first
    sort(s.begin(), s.end());

    int l = 0;

    int r = 0;

    while (l < m && r < n)
    {

        if (g[r] <= s[l])
        {

            r++;
        }

        l++;
    }

    return r;
}

int main()
{
    vector<int> g = {1, 2, 3}, s = {1, 1};
    cout << findContentChildren(g, s) << endl;
    return 0;
}