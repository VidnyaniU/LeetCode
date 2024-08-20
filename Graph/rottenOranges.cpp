#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;

    int vis[n][m];
    int cntfresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }

            else
            {
                vis[i][j] = 0;
            }

            if (grid[i][j] == 1)
                cntfresh++;
        }
    }

    int time = 0;
    // for neighbouring oranges
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};
    int count = 0;

    // BFS
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();
        // neighbouring oranges check
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, time + 1});
                vis[nrow][ncol] = 2;
                count++;
            }
        }
    }
    // if all the fresh oranges have not been converted return -1
    if (count != cntfresh)
        return -1;
    return time;
}
