#include <bits/stdc++.h>
using namespace std;
// CAN PLACE FLOWERS
// You have a long flowerbed in which some of the plots are planted, and some are not.
//  However, flowers cannot be planted in adjacent plots.
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int count = 0;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if (flowerbed[i] == 0)
        {
            int prev = (i == 0 || flowerbed[i - 1] == 0) ? 0 : 1;
            int next = ((i == flowerbed.size() - 1) || flowerbed[i + 1] == 0) ? 0 : 1;
            if (prev == 0 && next == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
    }

    return count >= n;
}
int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1, 0, 0};
    int n = 1;
    cout << canPlaceFlowers(flowerbed, n);
    return 0;
}