#include <bits/stdc++.h>
using namespace std;
long long maximumImportance(int n, vector<vector<int>> &roads)
{
    vector<long long> count(n, 0);
    for (auto &a : roads)
    {
        count[a[0]]++;
        count[a[1]]++;
    }
    sort(count.begin(), count.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ((i + 1) * count[i]);
    }

    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    maximumImportance(n, roads);
    return 0;
}