#include <bits/stdc++.h>
using namespace std;

/*Given an integer array of coins[ ] of size N representing different types of denominations and an integer sum,
the task is to count all combinations of coins to make a given value sum.  */

// count(coins,n,sum) = count(coins, n, sum-count[n-1]) + count(coins, n-1, sum)
int countWays(vector<int> coins, int n, int sum)
{

    if (sum == 0)
        return 1;
    if (sum < 0 || n == 0)
        return 0;

    return countWays(coins, n, sum - coins[n - 1]) + countWays(coins, n - 1, sum);
}
int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout << "Number of ways :: " << countWays(coins, coins.size(), sum) << endl;
    return 0;
}