#include <bits/stdc++.h>
using namespace std;
int passThePillow(int n, int time)
{
    if (time < n)
        return time + 1;
    int rounds_completed = time / (n - 1);
    int remaining_passes = time % (n - 1);

    if (rounds_completed % 2 == 0)
        return remaining_passes + 1;
    return n - remaining_passes;
}

int main()
{
    int n = 18;
    int time = 38;
    cout << passThePillow(n, time) << endl;
    return 0;
}