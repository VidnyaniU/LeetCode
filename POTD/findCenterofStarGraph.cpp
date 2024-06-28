#include <bits/stdc++.h>
using namespace std;
//Find center of a star graph
int findCenter(vector<vector<int>> &edges)
{
    vector<int> firstEdge = edges[0];
    vector<int> secondEdge = edges[1];

    // check if firstEdge[0] is present in secondEdge[0] or secondEdge[1]
    if (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1])
        return firstEdge[0];
    else
        return firstEdge[1];
}
int main()
{

    return 0;
}