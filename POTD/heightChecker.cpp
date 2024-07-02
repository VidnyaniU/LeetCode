#include <bits/stdc++.h>
using namespace std;
int heightChecker(vector<int> &heights)
{
    vector<int> sorted_heights = heights;
    sort(sorted_heights.begin(), sorted_heights.end());
    int count = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (heights[i] != sorted_heights[i])
            count++;
    }
    return count;
}
int main()
{
    vector<int> heights = {1, 1, 2, 1, 4, 1};
    cout << heightChecker(heights) << endl;

    return 0;
}