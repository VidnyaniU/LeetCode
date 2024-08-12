#include <bits/stdc++.h>
using namespace std;
void decToBinary(int n)
{
    vector<int> res;
    while (n > 0)
    {

        res.push_back(n % 2);
        n = n / 2;
    }

    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
}

int main()
{
    int num = 13;
    decToBinary(num);
    return 0;
}