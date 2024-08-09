#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}
int main()
{
    int n = 12;
    cout << isPowerOfTwo(n);
    return 0;
}