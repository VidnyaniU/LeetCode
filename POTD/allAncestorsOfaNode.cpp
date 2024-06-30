#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, ans;
void DFS(int curr, int parent)
{
    for (int child : adj[curr])
    {
        if (!ans[child].empty() && ans[child].back() == parent)
            continue;
        ans[child].push_back(parent);
        DFS(child, parent);
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{

    adj.resize(n);
    ans.resize(n);
    for (auto &edge : edges)
        adj[edge[0]].push_back(edge[1]);
    for (int i = 0; i < n; i++)
        DFS(i, i);
    return ans;
}
int main()
{
    int n = 8;
    vector<vector<int>> edgeList = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
    vector<vector<int>> ans = getAncestors(n, edgeList);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}