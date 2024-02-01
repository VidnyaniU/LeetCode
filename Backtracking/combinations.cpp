#include <iostream>
#include <vector>
using namespace std;

class combination
{
public:
    void help(int i, int n, int k, vector<int> &subset, vector<vector<int>> &ans)
    {
        // when the subset is smaller than what we want k will be positive when it is larger then k is negative hence taking k==0
        if (k == 0) // this  will save us from having subsets of larger sizes
        {
            // cout << subset << endl;
            ans.push_back(subset);
            return;
        }
        if (k > n - i + 1) // skipping the combinations which may not have chance to get k elements
            return;

        if (i > n)
            return;

        // for every element we have two option take the element or skip it
        // take the ith element
        subset.push_back(i);
        help(i + 1, n, k - 1, subset, ans);

        // skip the ith element
        subset.pop_back();
        help(i + 1, n, k, subset, ans);
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> subset;
        vector<vector<int>> ans;
        help(1, n, k, subset, ans);
        return ans;
    }
};
