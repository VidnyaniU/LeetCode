// print the highest and lowest frequency numbers
#include <bits/stdc++.h>
using namespace std;
void highLowFrequency(int n, int nums[])
{
    unordered_map<int, int> mapp;
    for (int i = 0; i < n; i++)
    {
        mapp[nums[i]]++;
    }

    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for (auto it : mapp)
    {
        int count = it.second;
        int element = it.first;
        if (count > maxFreq)
        {
            maxEle = element;
            maxFreq = count;
        }
        if (count < minFreq)
        {
            minEle = element;
            minFreq = count;
        }
    }

    cout << "Highest frequency element is : " << maxEle << " with frequency " << maxFreq << endl;
    cout << "Lowest frequency element is : " << minEle << " with frequency " << minFreq << endl;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    int nums[n] = {1, 4, 2, 3, 6, 4};

    highLowFrequency(n, nums);

    return 0;
}
