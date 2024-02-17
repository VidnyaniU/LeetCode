// Kids With the Greatest Number of Candies
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result(candies.size());
        int i = 0;
        int max = *max_element(candies.begin(), candies.end()); // first we will find the kid with maximum candies
        // for (; i < candies.size(); i++)
        // {
        //     if (candies[i] > max)
        //     {
        //         max = candies[i];
        //     }
        // }
        // compare it with all the elements by adding extra candies to them
        for (; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
                result[i] = true;

            else
                result[i] = false;
        }

        return result;
    }
};
int main()
{
    vector<int> candies;
    int extraCandies = 3;
    candies.push_back(2);
    candies.push_back(3);
    candies.push_back(5);
    candies.push_back(1);
    candies.push_back(3);

    vector<bool> result(candies.size());

    Solution s1;
    result = s1.kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < candies.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}