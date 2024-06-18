#include <bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int c)
{
    long long l = 0, r = sqrt(c);
    while (l <= r)
    {
        if (l * l + r * r == c)
            return true;
        if (l * l + r * r > c)
            r--;
        else
            l++;
    }

    return false;
}
int main()
{
    int c = 5;
    cout << judgeSquareSum(c);
    return 0;
}