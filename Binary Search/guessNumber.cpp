#include <bits/stdc++.h>
using namespace std;
int guess(int num)
{
    int pick = 9;
    if (num > pick)
        return 1;
    else if (num < pick)
        return -1;
    else
        return 0;
}
int guessNumber(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (guess(mid) == -1) // eliminate right half
            high = mid;
        else if (guess(mid) == 1)
            low = mid + 1; // eliminate left half
        else
            return mid;
    }

    return 0;
}
int main()
{

    return 0;
}