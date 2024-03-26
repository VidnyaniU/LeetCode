#include <bits/stdc++.h>
using namespace std;
// Find the Difference of Two Arrays
vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s1, s2;

    // sets to take unique values from both the arrays
    for (auto it : nums1)
    {
        s1.insert(it);
    }
    for (auto it : nums2)
    {
        s2.insert(it);
    }

    vector<int> v1, v2;
    for (auto it : s1)
    {
        if (s2.find(it) == s2.end())

            v1.push_back(it);
    }

    for (auto it : s2)
    {
        if (s1.find(it) == s1.end())

            v2.push_back(it);
    }
    vector<vector<int>> ans;
    ans.push_back(v1);
    ans.push_back(v2);
    return ans;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 3, 5, 6};
    vector<vector<int>> ans = findDifference(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}