#include <bits/stdc++.h>
using namespace std;
// using adjacency matrix
void adjMatrixGraph(int n, int m)
{
    int adj[n + 1][n + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}



void adjListGraph(int n, int m)
{

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for directed graph we won't need this
    }
}
int main()
{

    return 0;
}