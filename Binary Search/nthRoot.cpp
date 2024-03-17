#include <bits/stdc++.h>
using namespace std;
// find the  nth root of a number else return -1

// to find nth power of i
long long utilityF(int i, int n)
{
    long long ans = 1;
    long long base = i;

    while (n > 0)
    {
        if (n % 2)
        {
            n--;
            ans = ans * base;
        }
        else
        {
            n /= 2;
            base = base * base;
        }
    }
    return ans;
}
long long nthRootBrute(int n, long long number)
{
    for (int i = 1; i <= number; i++)
    {
        if (utilityF(i, n) == number)
        {
            return i;
        }
        else if (utilityF(i, n) > number)
        {
            break;
        }
    }

    return -1;
}

long long nthRootBS(int n, long long number)
{
    int low = 1, high = number;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (utilityF(mid, n) == number)
            return mid;
        else if (utilityF(mid, n) > number)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}
int main()
{
    // cout << nthRootBrute(3, 27)<<endl;
    cout << nthRootBS(3, 27) << endl;

    return 0;
}