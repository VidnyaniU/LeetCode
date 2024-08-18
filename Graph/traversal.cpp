#include <bits/stdc++.h>
using namespace std;

// BFS traversal
vector<int> bfsTraversal(int v, vector<int> adj[]) // v is number of vertices and adj is adjacency list
{
    vector<int> bfs;

    int vis[v] = {0}; // visited array with 0 base indexing
    vis[0] = 1;

    queue<int> qu;
    qu.push(0);

    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        bfs.push_back(node);

        // neighbouring elements
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                qu.push(it);
            }
        }
    }

    return bfs;
}

// DFS traversal
void dfs(int node, vector<int> adj[], vector<int> &ls, int vis[])
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {

        if (!vis[it])
        {
            dfs(it, adj, ls, vis);
        }
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, ls, vis);
    return ls;
}