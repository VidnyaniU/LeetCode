#include <bits/stdc++.h>
using namespace std;
bool threeConsecutiveOdds(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 1)
        {
            count += 1;
            if (count == 3)
                return true;
        }
        else
            count = 0;
    }
    return false;
}
int main()
{
    vector<int> arr = {1, 2, 1, 1};
    cout << threeConsecutiveOdds(arr) << endl;

    return 0;
}