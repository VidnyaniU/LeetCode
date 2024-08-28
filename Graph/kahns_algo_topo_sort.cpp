#include <bits/stdc++.h>
using namespace std;
// Topological sort using Kahn's algorithm
vector<int> topoSortKahn(int V, vector<int> adj[])
{
    // indegree list
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    // initially pushing elements with 0 indegree to the queue
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // node is in the topo so removing it

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}
