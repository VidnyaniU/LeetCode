#include <bits/stdc++.h>
using namespace std;
// using adjacency matrix
void adjGraph(int n, int m)
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
int main()
{

    return 0;
}