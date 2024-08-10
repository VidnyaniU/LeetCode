#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int res = start ^ goal;
    int count = 0;
    while (res)
    {
        count += res & 1;
        res >>= 1;
    }
    return count;
}
int main()
{
    int start = 10, goal = 7;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}