// to find union of two sorted arrays

#include <bits/stdc++.h>
using namespace std;

// Brute force approach using set
vector<int> unionBrute(vector<int> &nums1, vector<int> &nums2)
{
    set<int> uniSet;
    vector<int> unionArr;

    for (int i = 0; i < nums1.size(); i++)
    {
        uniSet.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        uniSet.insert(nums2[i]);
    }

    for (auto it : uniSet)
    {
        unionArr.push_back(it);
    }

    return unionArr;
}

// optimal using two pointers approach
vector<int> unionOptimal(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> unionAr;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m)
    {
        // check if element in the first array lesser than the element in the second
        if (nums1[i] < nums2[j])
        {
            // check if its the first element to put in the union or check the previous element of the uniono array if its different
            if (unionAr.size() == 0 || unionAr.back() != nums1[i])
            {
                unionAr.push_back(nums1[i]);
                i++;
            }
        }

        else
        {
            if (unionAr.size() == 0 || unionAr.back() != nums2[j])
            {
                unionAr.push_back(nums2[j]);
                j++;
            }
        }
    }

    // leftover elements in nums1 if any
    while (i < n)
    {
        if (unionAr.back() != nums1[i])
        {
            unionAr.push_back(nums1[i]);
            i++;
        }
    }

    // leftover elements in nums2 if any
    while (j < m)
    {
        if (unionAr.back() != nums1[i])
        {
            unionAr.push_back(nums2[j]);
            j++;
        }
    }
    return unionAr;
}
int main()
{
    vector<int> nums1 = {1, 1, 2, 3, 4, 4};
    vector<int> nums2 = {1, 2, 4, 5, 6};

    // vector<int> unionA = unionBrute(nums1, nums2);
    vector<int> unionA = unionOptimal(nums1, nums2);

    for (int i = 0; i < unionA.size(); i++)
    {
        cout << unionA[i];
    }

    return 0;
}