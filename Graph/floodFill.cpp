#include <bits/stdc++.h>
using namespace std;
void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, int initialColor, int newColor, int delRow[], int delCol[])
{

    ans[sr][sc] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {

        int nrow = sr + delRow[i];
        int ncol = sc + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, initialColor, newColor, delRow, delCol);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image; // copy the image
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    dfs(sr, sc, ans, image, initialColor, color, delRow, delCol);

    return ans;
}
