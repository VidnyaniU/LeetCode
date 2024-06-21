#include <bits/stdc++.h>
using namespace std;
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int initial = 0;
    int maxExtra = 0;
    int current = 0;

    for (int i = 0; i < customers.size(); i++)
    {
        if (grumpy[i] == 0)
            initial += customers[i]; // already satisfied customers
        else if (i < minutes)
            current += customers[i]; // first window from 0 to 2
    }
    maxExtra = current;
    for (int i = minutes; i < customers.size(); i++)
    {
        current += customers[i] * grumpy[i];
        current -= customers[i - minutes] * grumpy[i - minutes];
        maxExtra = max(maxExtra, current);
    }

    return initial + maxExtra;
}
int main()
{
    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;

    cout << maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}