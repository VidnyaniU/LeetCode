#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adjList[], vector<bool> &vis)
{
    vis[node] = 1;
    for (auto it : adjList[node])
    {
        if (!vis[it])
        {
            dfs(it, adjList, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    // convert matrix to list
    vector<int> adjList[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    // find the number of provinces
    vector<bool> vis(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, adjList, vis);
        }
    }

    return cnt;
}
