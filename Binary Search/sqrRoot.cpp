#include <bits/stdc++.h>
using namespace std;

// return the floor value as the sqr root
// Ex. sqrroot of 6 lies between 2 and 3 so we return 2
int sqrRoot(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid * mid) <= n)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return high;
}
int main()
{
    cout << sqrRoot(6) << endl  ;
    return 0;
}