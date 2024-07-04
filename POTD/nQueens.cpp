#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<string> &nQueens, int row, int col, int &n)
    {
        // check column
        for (int i = 0; i != row; ++i)
        {
            if (nQueens[i][col] == 'Q')
                return false;
        }

        // check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (nQueens[i][j] == 'Q')
                return false;
        }

        // check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (nQueens[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solveNQueens(vector<vector<string>> &ans, vector<string> &nQueens, int row, int &n)
    {
        if (row == n)
        {
            ans.push_back(nQueens);
            return;
        }

        for (int col = 0; col != n; ++col)
        {
            if (isSafe(nQueens, row, col, n))
            {
                nQueens[row][col] = 'Q'; // place the queen
                solveNQueens(ans, nQueens, row + 1, n);
                nQueens[row][col] = '.'; // remove the queen
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(ans, nQueens, 0, n);
        return ans;
    }
};
