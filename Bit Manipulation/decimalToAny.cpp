#include <bits/stdc++.h>
using namespace std;
void decToAny(int n, int base)
{
    string res;
    while (n > 0)
    {
        int rem = n % base;
        if (rem < 10)
            res.push_back(rem);
        else
            res.push_back(rem - 10 + 'A');
        n = n / base;
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}
int main()
{
    int n = 100;
    int base = 8;
    decToAny(n, base);
    return 0;
}