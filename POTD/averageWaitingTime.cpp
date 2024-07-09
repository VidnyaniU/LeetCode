#include <bits/stdc++.h>
using namespace std;
double averageWaitingTime(vector<vector<int>> &customers)
{
    int n = customers.size();
    int finish_time = 0;
    double wait_time = 0;
    for (auto &customer : customers)
    {
        int arrival = customer[0], time = customer[1];
        finish_time = max(finish_time, arrival) + time;
        wait_time += finish_time - arrival;
    }
    return (double)wait_time / n;
}
int main()
{
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    cout << averageWaitingTime(customers) << endl;
    return 0;
}