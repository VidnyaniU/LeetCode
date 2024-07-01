#include <bits/stdc++.h>
using namespace std;

// using DSU
bool static comp(vector<int> &a, vector<int> &b) { return a[0] > b[0]; }
int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent);
}

bool unite(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v)
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
    return false;
}

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    vector<int> parentAlice(n + 1);
    vector<int> parentBob(n + 1);
    vector<int> aliceRank(n + 1);
    vector<int> bobRank(n + 1);

    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < parentAlice.size(); i++)
    {
        parentAlice[i] = i;
        parentBob[i] = i;
        aliceRank[i] = 1;
        bobRank[i] = 1;
    }

    int removeEdges = 0;
    int mergeAlice = 1;
    int mergeBob = 1;
    for (auto it : edges)
    {
        // first preference to type 3
        if (it[0] == 3)
        {
            bool tempAlice = unite(it[1], it[2], parentAlice, aliceRank);
            bool tempBob = unite(it[1], it[2], parentBob, bobRank);

            if (tempAlice == true)
                mergeAlice++;
            if (tempBob == true)
                mergeBob++;
            if (tempAlice == false && tempBob == false)
                removeEdges++;
        }
        else if (it[0] == 1)
        {
            bool tempAlice = unite(it[1], it[2], parentAlice, aliceRank);
            if (tempAlice == true)
                mergeAlice++;
            else
                removeEdges++;
        }
        else
        {
            bool tempBob = unite(it[1], it[2], parentBob, bobRank);

            if (tempBob == true)
                mergeBob++;
            else
                removeEdges++;
        }
    }

    if (mergeAlice != n || mergeBob != n)
        return -1; // all edges cannot  be traversed
    return removeEdges;
}
