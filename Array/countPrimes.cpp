// Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

// return the count of primes until n
void countPrimes(int n)
{
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
}
int main()
{
    int n = 10;
    countPrimes(n);
    return 0;
}