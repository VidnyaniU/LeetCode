#include <bits/stdc++.h>
using namespace std;
int equalPairs(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> col;
        for (int j = 0; j < grid[0].size(); j++)
        {
            col.push_back(grid[j][i]);
        }

        for (int k = 0; k < grid[0].size(); k++)
        {
            vector<int> row = grid[k];
            if (row == col)
                count++;
        }
    }
    return count;
}
