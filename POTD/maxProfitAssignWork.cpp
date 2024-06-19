#include <bits/stdc++.h>
using namespace std;
int binaryS(vector<pair<int, int>> list, int target)
{
    int low = 0, high = list.size() - 1;
    while (low <= high)
    {
        int mid = (low + (high - low)) / 2;
        if (list[mid].first <= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    // store difficulty and profit in pairs and sort
    vector<pair<int, int>> difficulty_profit;
    for (int i = 0; i < difficulty.size(); i++)
        difficulty_profit.emplace_back(difficulty[i], profit[i]);
    sort(difficulty_profit.begin(), difficulty_profit.end());

    // store  difficulty with maximum profit
    vector<pair<int, int>> max_profit_for_difficulty;
    int max_profit = 0;
    for (auto &iter : difficulty_profit)
    {
        int d = iter.first, p = iter.second;
        max_profit = max(max_profit, p);
        max_profit_for_difficulty.emplace_back(d, max_profit);
    }

    int total_profit = 0;
    for (int w : worker)
    {
        int ind = binaryS(max_profit_for_difficulty, w);
        if (ind >= 0 && w >= max_profit_for_difficulty[ind].first)
            total_profit += max_profit_for_difficulty[ind].second;
        }
    return total_profit;
}
int main()
{

    return 0;
}