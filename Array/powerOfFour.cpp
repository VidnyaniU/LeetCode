#include <bits/stdc++.h>
using namespace std;
bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    return (0.5 * log2(1.0 * int(n)) == int(log2(int(n)) / 2));
}
int main()
{
    int n = 16;
    cout << isPowerOfFour(n) << endl;

    return 0;
}