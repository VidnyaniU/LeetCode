// intersection of two sorted arrays
#include <bits/stdc++.h>

using namespace std;
vector<int> intersectionBrute(vector<int> nums1, vector<int> nums2, int n1, int n2)
{
    vector<int> ans;
    bool vis[n2] = {0};
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (nums1[i] < nums2[j] && vis[j] == 0)
            {
                ans.push_back(nums1[i]);
                vis[j] = 1;
                break;
            }
            if (nums2[j] > nums1[i])
            {
                break;
            }
        }
    }

    return ans;
}

vector<int> intersectionOptimal(vector<int> nums1, vector<int> nums2, int n1, int n2)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums1 = {1, 1, 2, 3, 4, 4};
    vector<int> nums2 = {1, 2, 4, 5, 6};
    int n1 = nums1.size();

    int n2 = nums2.size();
    // vector<int> intersectionArr = intersectionBrute(nums1, nums2, n1, n2);
    vector<int> intersectionArr = intersectionOptimal(nums1, nums2, n1, n2);

    for (int i = 0; i < intersectionArr.size(); i++)
    {
        cout << intersectionArr[i];
    }

    return 0;
}