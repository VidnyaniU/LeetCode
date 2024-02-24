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

//optimal using two pointers approach
vector <int > unionOpitmal(vector<int> &nums1, vector<int> &nums2){
    vector <int> unionAr;

    return unionAr;
}
int main()
{
    vector<int> nums1 = {1, 1, 2, 3, 4, 4};
    vector<int> nums2 = {1, 2, 4, 5, 6};

    vector<int> unionA = unionBrute(nums1, nums2);
    for (int i = 0; i < unionA.size(); i++)
    {
        cout << unionA[i];
    }

    return 0;
}