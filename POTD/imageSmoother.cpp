#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &img)
{
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int start_row = row == 0 ? 0 : row - 1;
            int end_row = row == (m - 1) ? row : row + 1;

            int start_col = col == 0 ? 0 : col - 1;
            int end_col = col == (n - 1) ? col : col + 1;
            int val = 0;
            int cell_count = 0;
            for (int i = start_row; i <= end_row; i++)
            {

                for (int j = start_col; j <= end_col; j++)
                {
                    val += img[i][j];
                    cell_count++;
                }
            }
            ans[row][col] = val / cell_count;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> img = img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    imageSmoother(img);
    return 0;
}
