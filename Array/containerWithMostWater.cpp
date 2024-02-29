// Container With Most Water
#include <bits/stdc++.h>
using namespace std;
int mostWater(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = width * h;

        maxArea = max(maxArea, area);

        if (height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return maxArea;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << mostWater(height);
    return 0;
}