#include <bits/stdc++.h>
using namespace std;
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freqMap;
    for (auto it : arr)
    {
        freqMap[it]++;
    }
    unordered_set<int> uniqueFreq;
    for (auto it : freqMap)
    {
        uniqueFreq.insert(it.second);
    }
    return freqMap.size() == uniqueFreq.size();
}
int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 3, 4}; // this should return false
    cout << uniqueOccurrences(arr);

    return 0;
}