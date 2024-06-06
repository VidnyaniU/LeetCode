#include <bits/stdc++.h>
using namespace std;
string predictPartyVictory(string senate)
{
    queue<int> radiant, dire;
    int n = senate.length();

    // add all the senators to the respected queues
    for (int i = 0; i < n; i++)
    {
        if (senate[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    // use increasing n to keep track of the position
    while (!radiant.empty() && !dire.empty())
    {
        // only winner stays in the queue
        if (radiant.front() < dire.front())
            radiant.push(n++);
        else
            dire.push(n++);
        radiant.pop();
        dire.pop();
    }

    return (radiant.empty()) ? ("Dire") : ("Radiant");
}
int main()
{
    string senate = "RDD";
    cout << predictPartyVictory(senate);
    return 0;
}