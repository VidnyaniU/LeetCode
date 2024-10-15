#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &arr, int target)
{
    int i = 0, j = 0;
    int sum = 0, count = 0;
    while (j < arr.size())
    {
        sum = arr[i] + arr[j];
        if (sum == target)
        {
            count++;
            i++;
        }
        j++;
    }
    return count;
}
int main()
{

    return 0;
}