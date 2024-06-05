#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
public:
    queue<int> q;
    int ping(int t)
    {
        int temp = t - 3000;
        while (!q.empty() && temp > q.front())
            q.pop();
        q.push(t);

        return q.size();
    }
};
